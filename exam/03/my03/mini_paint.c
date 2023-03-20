#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		W;
int		H;
char	BG;
char	**TAB;

typedef struct draw
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}	Draw;

int	err_msg(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		printf("%s\n", "Error: Operation file corrupted");
	else if (err == -1)
		printf("%s\n", "Error: argument");
	else
		for (int i = 0; i < H; i++)
			printf("%s\n", TAB[i]);
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
	float	sqr;
	int		res;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c\n", &W, &H, &BG)) == 3)
		{
			if (0 < W && W <= 300 && 0 < H && H <= 300)
			{
				TAB = malloc(W * sizeof(char));
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(W * sizeof(char));
					memset(TAB[i], BG, W);
				}

