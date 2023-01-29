/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:47:57 by yback             #+#    #+#             */
/*   Updated: 2023/01/29 16:08:04 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_X 2.0
# define MIN_X -2.0
# define MAX_Y 2.0
# define MIN_Y -2.0
# define MAX_ITER 130
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MANDALBROT 1
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
int		zoom(int keycode, int x, int y, mlx_data *mlx);
int		keycode_funcs(int keycode, mlx_data *mlx);
int		ft_strcmp(char *s1, char *s2);
void	init_mlx(mlx_data *mlx, char **argv);
void	my_mlx_pixel_put(mlx_data *mlx, int color);
void	mandelbrot_check(double c_x, double c_y, int iter, mlx_data *mlx);
void	julia_check(double z_x, double z_y, int iter, mlx_data *mlx);
void	burningship_check(double c_x, double c_y, int iter, mlx_data *mlx);
void	draw_mandelbrot(mlx_data *mlx);
void	draw_julia(mlx_data *mlx);
void	draw_burningship(mlx_data *mlx);
float	ft_strtod(char *str, int decimal_found, int place);
int		what_sign(char *str, int *sign);
float	my_pow(int place);
double	my_abs(double num);
void	what_to_draw(char *fractal_type, mlx_data *mlx);
void	direct_to_draw(mlx_data *mlx);

#endif