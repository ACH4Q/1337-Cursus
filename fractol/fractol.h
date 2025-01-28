/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:37:05 by machaq            #+#    #+#             */
/*   Updated: 2025/01/27 15:44:40 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	c_re;
	double	c_im;
	int		max_iter;
	int		fractal_type;
}			t_data;

typedef struct s_range
{
	double	min;
	double	max;
}			t_range;

void		draw_fractal(t_data *data);
void		draw_julia(t_data *data);
void		draw_mandelbrot(t_data *data);
void		draw_burning_ship(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		map(double value, t_range from, t_range to);
double		ft_atof(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			handle_mouse(int button, int x, int y, t_data *data);
int			handle_key(int keycode, t_data *data);
int			close_window(t_data *data);
double		doubles(char *str, char *str1);
void		initialize_data(t_data *data);
double		ft_fabs(double x);
int			check_sign(const char *str, int *i);

#endif