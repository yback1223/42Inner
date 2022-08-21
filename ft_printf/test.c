#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
	int i;
	int j;
} testee;

void init(testee *test)
{
	test->i = 1;
	test->j = 2;
}

int plus(testee *test)
{
	return (test->i + test->j);
}

int	ft_atoi(char *arr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (arr[i])
		res = (res * 10) + (arr[i++] - '0');
	return (res);
}

int main(void)
{
	testee *test;
	char	word[10];
	test = malloc(sizeof(testee));
	init(test);
	word[0] = '1';
	word[1] = '2';
	word[2] = '3';
	word[3] = '\0';

	printf("%d %d\n", test->i, test->j);
	printf("%i\n", plus(test));

}