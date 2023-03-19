#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR_A "Error: argument"
#define ERROR_B "Error: Operation file corrupted"

typedef struct s_bg
{
	int	width;
	int	height;
	char	c;
}	t_bg;

typedef struct s_draw
{
	float	x;
	float	y;
	float	radius;
	char	c;
	char	type;
}	t_draw;

int	yb_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int	check_zone(FILE *file, t_bg *paper, char **draw)
{
	int	get;

	get = 0;
	if ((get = fscanf(file, "%d %d %c\n", &paper->width, &paper->height, &paper->c)) != 3)
		return (0);
	if (get == -1)
		return (0);
	if (300 < paper->width || paper->width <= 0 || 300 < paper->height || paper->height <= 0)
		return (0);
	*draw = calloc(paper->width * paper->height, sizeof(char));
	if (!(*draw))
		return (0);
	memset(*draw, paper->c, paper->width * paper->height);
	return (1);
}

int	create_circle(float x, float y, t_draw *circle)
{
	float	dist;

	dist = sqrtf(powf(x - circle->x, 2.) + powf(y - circle->y, 2.));
	if (dist <= circle->radius)
	{
		if (circle->radius - dist < 1.)
			return (2);
		return (1);
	}
	return (0);
}
