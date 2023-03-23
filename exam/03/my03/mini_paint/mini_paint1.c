#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct s_data
{
	int		w;
	int		h;
	char	c;
}			t_data;

typedef struct s_table
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	c;
}			t_table;

int	in_table(t_table table, int x, int y)
{
	return (sqrtf(powf(table.x - x, 2) + powf(table.y - y, 2)) <= table.r);
}

int	in_bord(t_table table, int x, int y)
{
	return (sqrtf(powf(table.x - x, 2) + powf(table.y - y, 2)) > table.r - 1);
}

void	draw(t_data data, t_table table, char *canvas)
{
	int	x;
	int	y;

	y = 0;
	while (y < data.h)
	{
		x = 0;
		while (x < data.w)
		{
			if (table.type == 'c' && in_table(table, x, y) && in_bord(table, x, y))
				canvas[y * data.w + x] = table.c;
			if (table.type == 'C' && in_table(table, x, y))
				canvas[y * data.w + x] = table.c;
			++x;
		}
		++y;
	}
}

void	print_canvas(t_data data, char *canvas)
{
	int	x;
	int	y;

	y = 0;
	while (y < data.h)
	{
		x = 0;
		while (x < data.w)
		{
			write(1, &canvas[y * data.w + x], 1);
			++x;
		}
		write(1, "\n", 1);
		++y;
	}
}

int	mini_paint(FILE *file)
{
	t_data	data;
	t_table	table;
	char	*canvas;
	int		ret;

	ret = 0;
	if ((fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c)) != 3)
		return (1);
	if (data.w <= 0 || data.w > 300 || data.h <= 0 || data.h > 300)
		return (1);
	if (!(canvas = malloc(sizeof(char) * data.w * data.h)))
		return (1);
	memset(canvas, data.c, data.w * data.h);
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &table.type, &table.x, &table.y, &table.r, &table.c)) == 5)
	{
		if (table.r <= 0 || (table.type != 'c' && table.type != 'C'))
		{
			free(canvas);
			return (1);
		}
		draw(data, table, canvas);
	}
	if (ret != EOF)
	{
		free(canvas);
		return (1);
	}
	print_canvas(data, canvas);
	free(canvas);
	return (0);
}

int	main(int ac, char *av[])
{
	FILE	*file;

	file = NULL;
	if (ac == 2)
	{
		if (!(file = fopen(av[1], "r")) || mini_paint(file))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
	}
	else
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	return (0);
}
