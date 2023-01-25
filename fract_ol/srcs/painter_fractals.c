/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:00:00 by yback             #+#    #+#             */
/*   Updated: 2023/01/25 09:37:08 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	mandelbrot_diver_conver_check(double c_x, double c_y, int iter, mlx_data *mlx)
{
	double	x_n_plus;
	double	y_n_plus;
	double	tmp_x_n_plus;

	x_n_plus = 0;
	y_n_plus = 0;
	while (iter < MAX_ITER)
	{
		tmp_x_n_plus = x_n_plus;
		x_n_plus = x_n_plus * x_n_plus - y_n_plus * y_n_plus + c_x;
		y_n_plus = 2 * tmp_x_n_plus * y_n_plus + c_y;
		if (x_n_plus * x_n_plus + y_n_plus * y_n_plus > 4)
		{
			my_mlx_pixel_put(mlx, mlx->color + 0x00008000 * iter);
			return;
		}
		iter++;
	}
	my_mlx_pixel_put(mlx, 0x00282828);
}

void	julia_diver_conver_check(double z_x, double z_y, int iter, mlx_data *mlx)
{
	double	x_n_plus;
	double	y_n_plus;
	double	tmp_x_n_plus;

	x_n_plus = z_x;
	y_n_plus = z_y;
	while (iter < MAX_ITER)
	{
		tmp_x_n_plus = x_n_plus;
		x_n_plus = x_n_plus * x_n_plus - y_n_plus * y_n_plus + mlx->julia_x;
		y_n_plus = 2 * tmp_x_n_plus * y_n_plus + mlx->julia_y;
		if (x_n_plus * x_n_plus + y_n_plus * y_n_plus > 4)
		{
			my_mlx_pixel_put(mlx, mlx->color + 0x00008000 * iter);
			return;
		}
		iter++;
	}
	my_mlx_pixel_put(mlx, 0x00282828);
}

void	burningship_diver_conver_check(double c_x, double c_y, int iter, mlx_data *mlx)
{
	double	x_n_plus;
	double	y_n_plus;
	double	tmp_x_n_plus;

	x_n_plus = 0;
	y_n_plus = 0;
	while (iter < MAX_ITER)
	{
		tmp_x_n_plus = x_n_plus;
		x_n_plus = x_n_plus * x_n_plus - y_n_plus * y_n_plus + c_x;
		y_n_plus = 2 * my_abs(tmp_x_n_plus * y_n_plus) + c_y;
		if (x_n_plus * x_n_plus + y_n_plus * y_n_plus > 4)
		{
			my_mlx_pixel_put(mlx, mlx->color + 0x00C0C0C0 * iter);
			return;
		}
		iter++;
	}
	my_mlx_pixel_put(mlx, 0x00282828);
}