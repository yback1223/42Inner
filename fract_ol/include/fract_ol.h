/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:47:57 by yback             #+#    #+#             */
/*   Updated: 2023/01/30 16:49:32 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define MAX_X 2.0
# define MIN_X -2.0
# define MAX_Y 2.0
# define MIN_Y -2.0
# define MAX_ITER 130
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# include "../minilibx/mlx.h"
# include <stdlib.h>

typedef struct m_data
{
	void	*mlx;
	void	*win;
	int		fractal_type;
	float	xmin;
	float	xmax;
	float	ymin;
	float	ymax;
	float	color;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mon_x;
	int		mon_y;
	double	julia_x;
	double	julia_y;
	int		julia_input_exist;
}	t_mlx;

int		ft_exit(void);
int		zoom_funcs(int keycode, int x, int y, t_mlx *mlx);
int		keycode_funcs(int keycode, t_mlx *mlx);
int		ft_strcmp(char *s1, char *s2);
void	init_mlx(t_mlx *mlx, char **argv);
void	my_mlx_pixel_put(t_mlx *mlx, int color);
void	mandelbrot_check(double c_x, double c_y, int iter, t_mlx *mlx);
void	julia_check(double z_x, double z_y, int iter, t_mlx *mlx);
void	burningship_check(double c_x, double c_y, int iter, t_mlx *mlx);
void	draw_mandelbrot(t_mlx *mlx);
void	draw_julia(t_mlx *mlx);
void	draw_burningship(t_mlx *mlx);
float	ft_strtod(char *str, int decimal_found, int place, float result);
int		what_sign(char *str, int *sign);
float	my_pow(int place);
double	my_abs(double num);
void	what_to_draw(char *fractal_type, t_mlx *mlx);
void	direct_to_draw(t_mlx *mlx);

#endif