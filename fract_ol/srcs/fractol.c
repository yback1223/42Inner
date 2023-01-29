/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:45:09 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 17:49:30 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	direct_to_draw(t_mlx *mlx)
{
	if (mlx->fractal_type == 1)
		draw_mandelbrot(mlx);
	if (mlx->fractal_type == 2)
		draw_julia(mlx);
	if (mlx->fractal_type == 3)
		draw_burningship(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	what_to_draw(char *fractal_type, t_mlx *mlx)
{
	if (ft_strcmp(fractal_type, "Mandelbrot") == 0)
		mlx->fractal_type = 1;
	if (ft_strcmp(fractal_type, "Julia") == 0)
		mlx->fractal_type = 2;
	if (ft_strcmp(fractal_type, "Burning Ship") == 0)
		mlx->fractal_type = 3;
	direct_to_draw(mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx mlx;

	if (argc < 2)
		return (0);
	if (3 <= argc && argc <= 4)
		mlx.julia_input_exist = 1;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0
		|| ft_strcmp(argv[1], "Julia") == 0
		|| ft_strcmp(argv[1], "Burning Ship") == 0)
	{
		init_mlx(&mlx, argv);
		what_to_draw(argv[1], &mlx);
		mlx_key_hook(mlx.win, keycode_funcs, &mlx);
		mlx_mouse_hook(mlx.win, zoom_funcs, &mlx);
		mlx_hook(mlx.win, 17, 2, ft_exit, 0);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
