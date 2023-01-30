/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:52 by yback             #+#    #+#             */
/*   Updated: 2023/01/30 16:46:46 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	init_julia_input(t_mlx *mlx, char **argv)
{
	if (mlx->julia_input_exist == 1)
	{
		mlx->julia_x = ft_strtod(argv[2], 0, 0, 0);
		mlx->julia_y = ft_strtod(argv[3], 0, 0, 0);
	}
	else
	{
		mlx->julia_x = 0.285;
		mlx->julia_y = 0.01;
	}
}

void	mlx_size_init(t_mlx *mlx)
{
	mlx->xmax = 2;
	mlx->xmin = -2;
	mlx->ymax = 2;
	mlx->ymin = -2;
}

void	init_mlx(t_mlx *mlx, char **argv)
{
	mlx->mlx = mlx_init();
	mlx_size_init(mlx);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	init_julia_input(mlx, argv);
	mlx->color = 0;
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

void	my_mlx_pixel_put(t_mlx *mlx, int color)
{
	char	*dst;

	dst = mlx->img_addr + (mlx->mon_y * mlx->line_length
			+ mlx->mon_x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
