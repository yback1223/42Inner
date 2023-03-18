#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define	ERROR_A "Error: argument"
#define ERROR_B "Error: Operation file corrupted"

typedef struct s_bg
{
	int		width;
	int		height;
	char	c;
}	t_bg;

typedef struct s_draw
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	c;
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
	if (!*draw)
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

void	draw_circle(t_bg *paper, char **draw, t_draw *circle)
{
	int	i;
	int	j;

	if (circle->type == 'C')
	{
		i = 0;
		while (i < paper->height)
		{
			j = 0;
			while (j < paper->width)
			{
				if (create_circle((float)j, (float)i, circle))
					(*draw)[i * paper->width + j] = circle->c;
				++j;
			}
			++i;
		}
	}
	else if (circle->type == 'c')
	{
		i = 0;
		while (i < paper-> height)
		{
			j = 0;
			while (j < paper->width)
			{
				if (create_circle((float)j, (float)i, circle) == 2)
					(*draw)[i * paper->width + j] = circle->c;
				++j;
			}
			++i;
		}
	}
}

int	check_circle(FILE *file, t_bg *paper, char **draw)
{
	t_draw	circle;
	int		get;

	get = 0;
	while ((get = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.c)) == 5)
	{
		if (!(circle.radius > 0 && (circle.type == 'c' || circle.type == 'C')))
			return (0);
		draw_circle(paper, draw, &circle);
	}
	if (get != -1)
		return (0);
	return (1);
}

void	paint_all(char *draw, t_bg paper)
{
	int	i;
	int	j;

	i = 0;
	while (i < paper.height)
	{
		j = 0;
		while (j < paper.width)
			printf("%c", draw[i * paper.width + j++]);
		printf("\n");
		++i;
	}
}

int	main(int ac, char **av)
{
	FILE	*file;
	t_bg	paper;
	char	*draw;

	memset(&paper, 0, sizeof(t_bg));
	if (ac != 2)
		return (yb_error(ERROR_A));
	if (!(file = fopen(av[1], "r")))
		return (yb_error(ERROR_B));
	if (!(check_zone(file, &paper, &draw)))
	{
		if (draw)
			free(draw);
		fclose(file);
		return (yb_error(ERROR_B));
	}
	if (!(check_circle(file, &paper, &draw)))
	{
		if (draw)
			free(draw);
		fclose(file);
		return (yb_error(ERROR_B));
	}
	paint_all(draw, paper);
	if (draw)
		free(draw);
	fclose(file);
	return (0);
}