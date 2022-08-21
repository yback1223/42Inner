#include <stdio.h>

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

void f(const char *str, int str_len)
{
  printf("%.*s\n", str_len, str);
}

int main() {
	int i = 0;

	while (i < 10)
	{
		if (i == 1)
		{
			printf("-----\n");
			return (0);
		}
		switch (i)
		{
			case 0:
				i++;
				break;
			

		}
	}
	printf("dfdfdfdfd");
}