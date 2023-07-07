UTM에서 debian bullseye OS로 VM 실행

VM에서는 `sudo startx`한 후에 firefox에서 yback.42.fr을 검색하면 https://yback.42.fr이 검색이 되어야 하고 그 사이트 안에는 mariadb가 연동된 wordpress가 실행되어야 한다.

해당 VM은 docker와 docker-compose가 이미 설치되어 있고, 필요한 디렉토리 또한 이미 다 만들어져 있다. 필요한 파일이나 디렉토리는 없다.

/inception/Makefile

```Makefile
name = inception
all:
	@bash srcs/requirements/wordpress/tools/yback_mkdir.sh
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

build:
	@bash srcs/requirements/wordpress/tools/yback_mkdir.sh
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env down

re:
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d --build

clean: down
	@docker system prune -a
	@sudo rm -rf ~/data/wordpress/*
	@sudo rm -rf ~/data/mariadb/*

fclean:
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
	@sudo rm -rf ~/data/wordpress/*
	@sudo rm -rf ~/data/mariadb/*

.PHONY	: all build down re clean fclean
```

/inception/srcs/.env

```
DOMAIN_NAME=yback.42.fr
CERT_=./requirements/tools/yback.42.fr
KEY_=./requirements/tools/yback.42.fr
DB_NAME=wordpress
DB_ROOT=123
DB_USER=wpuser
DB_PASS=123
```

/inception/srcs/docker-compose.yml

```YAML
version: '3'

services:

  mariadb:
    build:
      context: .
      dockerfile: requirements/mariadb/Dockerfile
    container_name: mariadb
    ports:
      - "3306:3306"
    networks:
      - inception
    volumes:
      - db-volume:/var/lib/mysql
    restart: always
  
  wordpress:
    build:
      context: .
      dockerfile: requirements/wordpress/Dockerfile
    container_name: wordpress
    depends_on:
      - mariadb
    networks:
      - inception
    volumes:
      - wp-volume:/var/www/
    restart: always

  nginx:
      build:
        context: .
        dockerfile: requirements/nginx/Dockerfile
      container_name: nginx
      depends_on:
        - wordpress
      ports:
        - "443:443"
      networks:
        - inception
      volumes:
        - ./requirements/nginx/conf/:/etc/nginx/http.d/
        - ./requirements/nginx/tools:/etc/nginx/ssl/
        - wp-volume:/var/www/
      restart: always

volumes:
  db-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/mariadb
  wp-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/wordpress

networks:
    inception:
        driver: bridge
```

/inception/srcs/requirements/mariadb/conf/yback_create_db.sh

```bash
#!bin/sh

cat << END > /tmp/yback_create_db.sql
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT}';
CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${DB_USER}'@'%' IDENTIFIED by '${DB_PASS}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
END

/usr/bin/mysqld --user=mysql --bootstrap < /tmp/yback_create_db.sql
rm -f /tmp/yback_create_db.sql

```

/inception/srcs/requirements/mariadb/Dockerfile

```Dockerfile
FROM debian:buster

# ARG DB_NAME \
#     DB_USER \
#     DB_PASS

RUN apt-get update && apt-get install -y mariadb-server mariadb-client

RUN mkdir /var/run/mysqld && chmod 777 /var/run/mysqld
RUN mkdir -p /etc/my.cnf.d && chmod 755 /etc/my.cnf.d

RUN echo '[mysqld]' > /etc/my.cnf.d/docker.cnf \
    && echo 'skip-host-cache' >> /etc/my.cnf.d/docker.cnf \
    && echo 'skip-name-resolve' >> /etc/my.cnf.d/docker.cnf \
    && echo 'bind-address=0.0.0.0' >> /etc/my.cnf.d/docker.cnf

RUN sed -i "s|skip-networking|skip-networking=0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

EXPOSE 3306

COPY requirements/mariadb/conf/yback_create_db.sh .
RUN chmod +x yback_create_db.sh \
    && ./yback_create_db.sh \
    && rm yback_create_db.sh

USER mysql
CMD ["/usr/sbin/mysqld", "--skip-log-error"]

```

/inception/srcs/requirements/nginx/conf/yback_nginx.conf

```
server {
    listen      443 ssl;
    server_name yback.42.fr www.yback.42.fr;

    root    /var/www;
    index index.php;
    
	ssl_certificate     /etc/nginx/ssl/yback.42.fr.crt;
    ssl_certificate_key /etc/nginx/ssl/yback.42.fr.key;
    ssl_protocols       TLSv1.2 TLSv1.3;
    ssl_session_timeout 10m;
    keepalive_timeout 70;
    
	location / {
        try_files $uri /index.php?$args;
        add_header Last-Modified $date_gmt;
        add_header Cache-Control 'no-store, no-cache';
        if_modified_since off;
        expires off;
        etag off;
    }
    
	location ~ \.php$ {
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
    }
}
```

/inception/srcs/requirements/nginx/tools/yback.42.fr.crt

```
-----BEGIN CERTIFICATE-----
MIIDazCCAlOgAwIBAgIUStkds90vCA08LALaFqIM1OGaluUwDQYJKoZIhvcNAQEL
BQAwRTELMAkGA1UEBhMCS1IxEzARBgNVBAgMClNvbWUtU3RhdGUxITAfBgNVBAoM
GEludGVybmV0IFdpZGdpdHMgUHR5IEx0ZDAeFw0yMzA2MTgwNzI2MDlaFw0yNDA2
MTcwNzI2MDlaMEUxCzAJBgNVBAYTAktSMRMwEQYDVQQIDApTb21lLVN0YXRlMSEw
HwYDVQQKDBhJbnRlcm5ldCBXaWRnaXRzIFB0eSBMdGQwggEiMA0GCSqGSIb3DQEB
AQUAA4IBDwAwggEKAoIBAQDWwizXnQ5DUa3/HSEOgRFSzANc3m5Jdn/xmzhq4pGz
IolKCCxHDs8MORzWTDnX8q0p7NyVlcFcokE06MVAt3r4IklatiD5rtnt6bYQraSR
4+bJ1B/P88LjRARJ5pdE8gsjLZTXqoBZiXcLyjYLsO3kcCsdrKcRUgtQtt8RwYxR
lLRZHIObIGO5cKQHkFWqqyFksbj6Xqy+lSo9Nlb8cEFnh03PREBOlmK0ZC/yQK21
QmkFWltkNhI4um39sOzwQGYw5LIHlidFdQWL2P4g26bIPz05UHqvKXlSLcdL1Oth
AuoR1g7GPcfeX8UKn9kUU+UH2WIJJC8yAmhF1PA3MmMHAgMBAAGjUzBRMB0GA1Ud
DgQWBBRI3gfFa6H03Tn1nu2snTyMevW7wjAfBgNVHSMEGDAWgBRI3gfFa6H03Tn1
nu2snTyMevW7wjAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQAJ
+/CgWkGa5WUVziJOp9UdtsvouxTJXBvZR6FIusbsk/bdXSjCWIjeW6YjVs8Zd9nZ
a4epFkRs3g0+XAh4UIv28rTT25qSSkX8HuZX+PSUWyYfn/118Jndr7LhacLqbPJ2
xjfE6dlZcswj5OpkNN4R7KiG52auQOrrXm1lBi8DmhgQRFaB02mbMARhVxS9EwU4
hKhwrv/Uc2Z+QkiyGae0LmHDJOoJ9Ywp0q+jqjiJCOkotHI8jDDyMIPeqSNJ72lF
CzIhxTP9uH8sDVkzlxUK9Ij7aK6MvRaEbqK19xdAocF+DUB7RCV3kcN0Y8ghXso/
btnqkMLs53KDLvI3SVNm
-----END CERTIFICATE-----

```

/inception/srcs/requirements/nginx/tools/yback.42.fr.key

```
-----BEGIN PRIVATE KEY-----
MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDWwizXnQ5DUa3/
HSEOgRFSzANc3m5Jdn/xmzhq4pGzIolKCCxHDs8MORzWTDnX8q0p7NyVlcFcokE0
6MVAt3r4IklatiD5rtnt6bYQraSR4+bJ1B/P88LjRARJ5pdE8gsjLZTXqoBZiXcL
yjYLsO3kcCsdrKcRUgtQtt8RwYxRlLRZHIObIGO5cKQHkFWqqyFksbj6Xqy+lSo9
Nlb8cEFnh03PREBOlmK0ZC/yQK21QmkFWltkNhI4um39sOzwQGYw5LIHlidFdQWL
2P4g26bIPz05UHqvKXlSLcdL1OthAuoR1g7GPcfeX8UKn9kUU+UH2WIJJC8yAmhF
1PA3MmMHAgMBAAECggEBAMcYSuQ1GST10z4gbiX5J+s/cZqmJ055ylFdmmcU1whg
azCz9QCHTRHC3OYa0sFNnJWynikbJaDQV21KopvFvf3OI30yPc3b+POkaIJ7yIbr
5miT/E4YaUOyKdutJ+3mCsc5GbT6v3TCiRfoBkS+aT0PdBlVl6jqC81vS8w1R/XU
FzlDRhAJpTjOhEXykzjU4MENe9ejvhhoua1RH35EyiN1bCPaGlDsYFNlo/opS8CV
hyRFcBWo7YfCNJl9j80P0Ly3rfa0wXQaEKyrI2ynHJ7XRgSWNy995ptRt+dR8Bk9
xdEPe+cydtdQSTx8zuQNzzJ4MiMGgDxHHivU+Du3IckCgYEA/wLZvSnxY777FJC0
GjtAwtLCTPYe37jTdoD0JeWFCi9axseN4Mz/zqWY26hQTZ2CzaMEI4n7VFFx5oyw
u2Qu/d8x0evOaiPlgLZh/vEv6LNW351BT/6mJ7r/u2X/Pg6Eh1J6zEn1WoZb3GFK
YpdNh5bClAgS/hCpXcSHA7ViK+UCgYEA15ddp+01mfRvXKw4hALapgGSMtSTPOLf
sHLcMSatFw1vGSynx+8CkciQTPiGQjG5OpehiHkonVA0d5DyZslQHAovcvbleQuv
pdbgjImfbN7pe5ssZZU51sY7ELWexOInWwMe/FPmLSokbSXPHilGNhHPxms+rPUt
F584PaotXHsCgYEA5zyLeqdk1wDfphdM6Rhfsgnw3F61QkLTpXpraU3FpKWqF+Pt
+DGLqLOqd0wZfTfd21/9qcg92Yh80wUyYMoIfnZ8M5EyvDZOrrczBz1nJwgwN1be
WY5c1lwP9rsXhwsdC6Qz67kIvYxmEeE61UnDqLaBPEBSEIXFPlyt3SQFoC0CgYAe
sgN4rFJsaBwO8spdKVbeOe0J5bBNA/RbWA83xEzyskv2JqCA2+veu9Kn0t6ywAei
awJpvu5kb4341B9fORx50Y1t7e9AK8THdO+lstaLFrXhjndkwzln9fNk7qb7W0PF
No2L2Zo1JgHntHFn1vKTMjgGBTD4STQxX88PIJKyzwKBgG2dVE1XUBe8qoXmK+3D
8mDP+zmoL4yW09xNkg0a+cUA02pI4YJKONeTzjNYIGWAAj8Jc4Bmf+9tB6utDK09
/4XbGFbHVDBbdUFyiPwOmHlijp04AHQFGDIrS2D4CYQ/uoOUgRUeafJbOveHtV3k
GXu0so0JF5Sn3cD0QcivoUUI
-----END PRIVATE KEY-----

```

/inception/srcs/requirements/nginx/Dockerfile

```Dockerfile
FROM debian:buster

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y --no-install-recommends nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

```

/inception/srcs/requirements/wordpress/conf/yback_wp_cnf_create.sh

```bash
#!bin/sh
if [ ! -f "/var/www/wp-config.php" ]; then
cat << EOF > /var/www/wp-config.php
<?php
define( 'DB_NAME', '${DB_NAME}' );
define( 'DB_USER', '${DB_USER}' );
define( 'DB_PASSWORD', '${DB_PASS}' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define('FS_METHOD','direct');
\$table_prefix = 'wp_';
define( 'WP_DEBUG', false );
EOF
fi
```

/inception/srcs/requirements/wordpress/tools/yback_mkdir.sh

```bash
# #!/bin/bash
# if [ ! -d "/home/${USER}/data" ]; then
#         mkdir /home/${USER}/data
#         mkdir /home/${USER}/data/mariadb
#         mkdir /home/${USER}/data/wordpress
# fi

sudo mkdir -p /home/$USER/data/mariadb
sudo mkdir -p /home/$USER/data/wordpress
sudo chown -R $USER:$USER /home/$USER/data

```

/inception/srcs/requirements/wordpress/Dockerfile

```Dockerfile
FROM debian:buster

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y --no-install-recommends \
    php-fpm php-mysqli php-json php-curl php-dom php-exif php-fileinfo php-mbstring php-xml php-zip wget unzip 

RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
      /etc/php/7.3/fpm/pool.d/www.conf && \
    sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" \
      /etc/php/7.3/fpm/pool.d/www.conf && \
    sed -i "s|;listen.group = nobody|listen.group = nobody|g" \
      /etc/php/7.3/fpm/pool.d/www.conf

RUN rm -rf /var/lib/apt/lists/*

WORKDIR /var/www

RUN wget --no-check-certificate https://wordpress.org/latest.zip && \
    unzip latest.zip && \
    cp -rf wordpress/* . && \
    rm -rf wordpress latest.zip

COPY ./requirements/wordpress/conf/yback_wp_cnf_create.sh .
RUN sh yback_wp_cnf_create.sh && rm yback_wp_cnf_create.sh && \
    chmod -R 0777 wp-content/

CMD ["/usr/sbin/php-fpm7.3", "-F"]

```

