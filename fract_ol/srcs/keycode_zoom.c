/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:57 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 16:04:11 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "../include/keycodes.h"

void	zoom_in(int x, int y, t_mlx *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / WIN_WIDTH;
	dy = (mlx->ymax - mlx->ymin) / WIN_HEIGHT;
	mlx->xmin = (mlx->xmin + ((dx * x) * 0.5));
	mlx->xmax = (mlx->xmax - ((dx * (WIN_WIDTH - x)) * 0.5));
	mlx->ymax = (mlx->ymax - ((dy * y) * 0.5));
	mlx->ymin = (mlx->ymin + ((dy * (WIN_HEIGHT - y)) * 0.5));
}

void	zoom_out(int x, int y, t_mlx *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / WIN_WIDTH;
	dy = (mlx->ymax - mlx->ymin) / WIN_HEIGHT;
	mlx->xmin = (mlx->xmin - ((dx * x) * 0.5));
	mlx->xmax = (mlx->xmax + ((dx * (WIN_WIDTH - x)) * 0.5));
	mlx->ymax = (mlx->ymax + ((dy * y) * 0.5));
	mlx->ymin = (mlx->ymin - ((dy * (WIN_HEIGHT - y)) * 0.5));
}

int	zoom_funcs(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == MOUSE_UP_ZOOM_IN)
		zoom_in(x, y, mlx);
	if (keycode == MOUSE_DOWN_ZOOM_OUT)
		zoom_out(x, y, mlx);
	direct_to_draw(mlx);
	return (0);
}
