#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error_handling(char *error_readmsg) {
	write(STDERR_FILENO, error_readmsg, strlen(error_readmsg));
	exit(1);
}

int	main(int ac, char **av) {
	if (ac != 2)
		error_handling("Wrong number of arguments\n");
	int servfd, clntfd, nfds;
	struct sockaddr_in servaddr, clntaddr;
	socklen_t clntaddrsize;
	fd_set afds, rfds;
	int ids[10000], id = 0;
	char readmsg[200000], broadmsg[200000], buf[200000];

	if ((servfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error_handling("Fatal error\n");
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(servfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		error_handling("Fatal error\n");
	if (listen(servfd, 5) < 0)
		error_handling("Fatal error\n");
	FD_ZERO(&afds);
	FD_SET(servfd, &afds);
	nfds = servfd + 1;
	memset(readmsg, 0, sizeof(readmsg));
	while (1) {
		rfds = afds;
		if (select(nfds, &rfds, NULL, NULL, NULL) < 0)
			error_handling("Fatal error\n");
		for (int ifd = 0; ifd < nfds; ifd++) {
			if (FD_ISSET(ifd, &rfds)) {
				if (ifd == servfd) {
					// join
					clntaddrsize = sizeof(clntaddr);
					if ((clntfd = accept(ifd, (struct sockaddr*)&clntaddr, &clntaddrsize)) < 0)
						error_handling("Fatal error\n");
					if (clntfd >= nfds)
						nfds = clntfd + 1;
					ids[clntfd] = id++;
					memset(broadmsg, 0, sizeof(broadmsg));
					sprintf(broadmsg, "server: client %d just arrived\n", ids[clntfd]);
					for (int i = 0; i < nfds; i++) {
						if (i != clntfd)
							send(i, broadmsg, strlen(broadmsg), 0);
					}
					FD_SET(clntfd, &afds);
				}
				else {
					if (recv(ifd, readmsg, 200000 - 1, 0) <= 0) {
						// left
						FD_CLR(ifd, &afds);
						memset(broadmsg, 0, sizeof(broadmsg));
						sprintf(broadmsg, "server: client %d just left\n", ids[ifd]);
						for (int i = 0; i < nfds; i++) {
							if (i != ifd)
								send(i, broadmsg, strlen(broadmsg), 0);
						}
						close(ifd);
						// ids[ifd] = id--; // 통과에 필요하지는 않았음
						break ;
					}
					else {
						// send msg
						memset(broadmsg, 0, sizeof(broadmsg));
						memset(buf, 0, sizeof(buf));
						for (int i = 0, j = 0; readmsg[i]; i++, j++) {
							buf[j] = readmsg[i];
							if (readmsg[i] == '\n') {
								sprintf(broadmsg, "client %d: %s", ids[ifd], buf);
								for (int k = 0; k < nfds; k++) {
									if (k != ifd)
										send(k, broadmsg, strlen(broadmsg), 0);
								}
								// 아래는 개행이 여러개 섞여 있는 경우, 시험에서 테스트6에 해당함
								j = -1;
								memset(broadmsg, 0, sizeof(broadmsg));
								memset(buf, 0, sizeof(buf));
							}
						}
						memset(readmsg, 0, sizeof(readmsg));
					}
				}
			}
		}
	}
	return (0);
}