#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct draw
{
	char	t;
	float	x;
	float 	y;
	float	r;
	char	c;
}	Draw;

int		W;
int		H;
char	BG;
char	**TAB;

int	err_msg(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		printf("%s\n", "Error: Operation file corrupted");
	else if (err == 1)
		printf("%s\n", "Error: argument");
	else
		for (int i = 0; i < H; i++)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
		}
	if (fd)
		fclose(fd);
	if (TAB)
	{
		for (int i = 0; i < H; i++)
			free(TAB[i]);
		free(TAB);
	}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	Draw	el;
	int		res;
	float	sqr;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (0 < W && W <= 300 && 0 < H && H <= 300)
			{
				TAB = malloc(H * sizeof(char *));
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(W * sizeof(char));
					memset(TAB[i], BG, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &el.t, &el.x, &el.y, &el.r, &el.c);
					if (res == EOF)
						return (err_msg(fd, 0));
					else if (res != 5 || el.r <= 0 || (el.t != 'c' && el.t != 'C'))
						break;
					for (int i = 0; i < H; i++)
					{
						for (int j = 0; j < W; j++)
						{
							sqr = sqrtf(powf(j - el.x, 2.0) + powf(i - el.y, 2.0));
							if (sqr <= el.r)
							{
								if (el.t == 'C' || (el.t == 'c' && el.r - sqr < 1.0f))
									TAB[i][j] = el.c;
							}
						}
					}
				}
			}
		}
		return (err_msg(fd, 2));
	}
}