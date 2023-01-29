/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:49:18 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 15:57:21 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "../include/keycodes.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

void	move_with_arrows(int keycode, mlx_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (keycode == ARROW_LEFT_MOVE_LEFT || keycode == ARROW_RIGHT_MOVE_RIGHT)
	{
		if (keycode == ARROW_LEFT_MOVE_LEFT)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
	}
	if (keycode == ARROW_UP_MOVE_UP || keycode == ARROW_DOWN_MOVE_DOWN)
	{
		if (keycode == ARROW_DOWN_MOVE_DOWN)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
}

int	keycode_funcs(int keycode, mlx_data *mlx)
{
	if (keycode == ESC_EXIT)
		exit(0);
	if (ARROW_LEFT_MOVE_LEFT <= keycode && keycode <= ARROW_UP_MOVE_UP)
		move_with_arrows(keycode, mlx);
	if (keycode == Q_CHANGE_COLOR_UP)
		mlx->color += 0x00008000;
	if (keycode == W_CHANGE_COLOR_DOWN)
		mlx->color -= 0x00008000;
	direct_to_draw(mlx);
	return (0);
}
