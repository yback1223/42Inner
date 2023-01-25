/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:13:56 by yback             #+#    #+#             */
/*   Updated: 2023/01/25 08:44:47 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"


void	draw_mandelbrot(mlx_data *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			double	z_x;
			double	z_y;

			z_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			z_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
			mandelbrot_diver_conver_check(z_x, z_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}

void	draw_julia(mlx_data *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			double	c_x;
			double	c_y;

			c_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			c_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
			julia_diver_conver_check(c_x, c_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}

void	draw_burningship(mlx_data *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);

	mlx->mon_y = 0;
	while (mlx->mon_y < WIN_HEIGHT)
	{
		mlx->mon_x = 0;
		while (mlx->mon_x < WIN_WIDTH)
		{
			double	z_x;
			double	z_y;

			z_x = MIN_X + mlx->mon_x * (MAX_X - MIN_X) / (double)WIN_WIDTH;
			z_y = MAX_Y - mlx->mon_y * (MAX_Y - MIN_Y) / (double)WIN_HEIGHT;
			burningship_diver_conver_check(z_x, z_y, 0, mlx);
			mlx->mon_x++;
		}
		mlx->mon_y++;
	}
}