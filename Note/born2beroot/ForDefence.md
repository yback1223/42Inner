# CentOS vs Debian

|CentOS|Debian|
|:--:|:--:|
|large community|less market preference|
|does not support many different architecture|has more packages|
|CentOS vesions are maintained for 10 years meaning there is great support for enterprise applications|Certain amount of good Linux knowledge is required to work with Debian|
|long gap for new versions because it's stable|2 years gap for new versions so it's stable|
|hard to upgrade|easy to upgrade|
|not free|free|
|does not have an easy GUI|has desktop friendly applications and GUI|

# SELinux vs AppArmor

|what|AppArmor|SELinux|
|:--:|:--:|:--:|
|controls access|based on the paths of the program files|based on the labels of the files and processes|
|administration difficulty|easy|hard, but more secure|
|motto|allow everything and tighten gradually|refuses everything and loosens up gradually|
|policy|default policy almost does not confine programs in the system, and lacks many supportive policy modules|has relatively complete policy modules for the system and all applications|

# changing hostname

```
$ sudo hostnamectl set-hostname <new-host-name>
```

```
hostnamectl
```