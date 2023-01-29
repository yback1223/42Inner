/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:13:56 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 16:08:12 by yback            ###   ########.fr       */
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
			c_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			c_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
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
			z_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			z_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
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
			z_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			z_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
			burningship_check(z_x, z_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}
