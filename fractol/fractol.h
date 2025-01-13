/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:37:05 by machaq            #+#    #+#             */
/*   Updated: 2025/01/13 14:46:15 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <signal.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  zoom;
    double  offset_x;
    double  offset_y;
    double  c_re;
    double  c_im;
    int     max_iter;
    int     fractal_type;
}           t_data;

void        draw_fractal(t_data *data);
void        draw_julia(t_data *data);
void        draw_mandelbrot(t_data *data);
int         handle_mouse(int button, int x, int y, t_data *data);
int         handle_key(int keycode, t_data *data);
void        my_mlx_pixel_put(t_data *data, int x, int y, int color);
double      map(double value, double min1, double max1, double min2, double max2);
void        signal_handler(int signum);
int         close_window(t_data *data);

#endif
