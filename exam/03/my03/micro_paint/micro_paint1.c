#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	float	w;
	float	h;
	char	c;
}			t_table;

int	in_table(t_table table, int x, int y)
{
	return (x >= table.x && table.x + table.w >= x && y >= table.y && table.y + table.h >= y);
}

int	in_bord(t_table table, int x, int y)
{
	return (x < table.x + 1 || table.x + table.w - 1 < x || y < table.y + 1 || table.y + table.h - 1 < y);
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
			if (table.type == 'r' && in_table(table, x, y) && in_bord(table, x, y))
				canvas[y * data.w + x] = table.c;
			if (table.type == 'R' && in_table(table, x, y))
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

int	micro_paint(FILE *file)
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
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &table.type, &table.x, &table.y, &table.w, &table.h, &table.c)) == 6)
	{
		if (table.w <= 0 || table.h <= 0 || (table.type != 'r' && table.type != 'R'))
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
		if (!(file = fopen(av[1], "r")) || micro_paint(file))
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
