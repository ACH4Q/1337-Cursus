/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:52:50 by machaq            #+#    #+#             */
/*   Updated: 2025/01/22 22:20:41 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	burning_ship_iterations(double c_re, double c_im, int max_iter)
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
		z_re = fabs(z_re);
		z_im = fabs(z_im);
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

static int	burning_ship_color(int iter, int max_iter)
{
	int	color;

	if (iter == max_iter)
	{
		color = 0x000000;
	}
	else
	{
		color = (iter * 255 / max_iter) << 16 | (iter * 255 / max_iter) << 8;
	}
	return (color);
}

void	draw_burning_ship(t_data *data)
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
			c_re = map(x, (t_range){0, WIDTH}, (t_range){-2.5 / data->zoom
					+ data->offset_x, 1.5 / data->zoom + data->offset_x});
			c_im = map(y, (t_range){0, HEIGHT}, (t_range){-2.0 / data->zoom
					+ data->offset_y, 1.5 / data->zoom + data->offset_y});
			iter = burning_ship_iterations(c_re, c_im, data->max_iter);
			my_mlx_pixel_put(data, x++, y, burning_ship_color(iter,
					data->max_iter));
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	initialize_data(t_data *data)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = 50;
}
