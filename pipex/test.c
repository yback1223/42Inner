#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		printf("fork() failed");
		exit(1);
	}
	printf("before ifs: %d\n", pid);
	if (pid = 0)
	{
		printf("자식 프로세스 정보\n");
		printf("변수 pid 값: %d\n", pid);
		printf("자식 pid: %d\n", getpid());
	}
	else
	{
		printf("부모 프로세스 정보\n");
		printf("변수 pid 값: %d\n", pid);
		printf("부모 pid: %d\n", getpid());
	}
	return (0);
}