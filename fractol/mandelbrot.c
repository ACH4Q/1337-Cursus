/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:53:51 by machaq            #+#    #+#             */
/*   Updated: 2025/01/22 22:20:45 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_iterations(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0.0;
	z_im = 0.0;
	iter = 0;
	while ((z_re * z_re + z_im * z_im <= 4) && (iter < max_iter))
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

static int	mandelbrot_color(int iter, int max_iter)
{
	int	color;

	if (iter == max_iter)
	{
		color = 0x000000;
	}
	else
	{
		color = (iter * 255 / max_iter) << 16;
	}
	return (color);
}

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_re = map(x, (t_range){0, WIDTH}, (t_range){-2.0 / data->zoom
					+ data->offset_x, 2.0 / data->zoom + data->offset_x});
			c_im = map(y, (t_range){0, HEIGHT}, (t_range){-2.0 / data->zoom
					+ data->offset_y, 2.0 / data->zoom + data->offset_y});
			iter = mandelbrot_iterations(c_re, c_im, data->max_iter);
			my_mlx_pixel_put(data, x, y, mandelbrot_color(iter,
					data->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
