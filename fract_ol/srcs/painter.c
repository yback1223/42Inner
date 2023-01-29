/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:13:56 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 17:59:48 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	draw_mandelbrot(t_mlx *mlx)
{
	double	c_x;
	double	c_y;

	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			c_x = mlx->xmin + mlx->mon_x
				* (mlx->xmax - mlx->xmin) / (double)WIN_WIDTH;
			c_y = mlx->ymax - mlx->mon_y
				* (mlx->ymax - mlx->ymin) / (double)WIN_HEIGHT;
			mandelbrot_check(c_x, c_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}

void	draw_julia(t_mlx *mlx)
{
	double	z_x;
	double	z_y;

	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			z_x = mlx->xmin + mlx->mon_x
				* (mlx->xmax - mlx->xmin) / (double)WIN_WIDTH;
			z_y = mlx->ymax - mlx->mon_y
				* (mlx->ymax - mlx->ymin) / (double)WIN_HEIGHT;
			julia_check(z_x, z_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}

void	draw_burningship(t_mlx *mlx)
{
	double	z_x;
	double	z_y;

	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			z_x = mlx->xmin + mlx->mon_x
				* (mlx->xmax - mlx->xmin) / (double)WIN_WIDTH;
			z_y = mlx->ymax - mlx->mon_y
				* (mlx->ymax - mlx->ymin) / (double)WIN_HEIGHT;
			burningship_check(z_x, z_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}
