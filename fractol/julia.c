/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:53:46 by machaq            #+#    #+#             */
/*   Updated: 2025/01/19 13:06:34 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	tmp;

	iter = 0;
	while ((z.re * z.re + z.im * z.im <= 4) && (iter < max_iter))
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		iter++;
	}
	return (iter);
}

static int	julia_color(int iter, int max_iter)
{
	int	color;

	if (iter == max_iter)
		color = 0x000000;
	else
		color = (iter * 255 / max_iter) << 16;
	return (color);
}

static void	draw_julia_pixel(t_data *data, int x, int y)
{
	int			iter;
	int			color;
	t_complex	z;
	t_complex	c;

	z.re = map(x, (t_range){0, WIDTH}, (t_range){-2.0 / data->zoom
			+ data->offset_x, 2.0 / data->zoom + data->offset_x});
	z.im = map(y, (t_range){0, HEIGHT}, (t_range){-2.0 / data->zoom
			+ data->offset_y, 2.0 / data->zoom + data->offset_y});
	c.re = data->c_re;
	c.im = data->c_im;
	iter = calculate_julia(z, c, data->max_iter);
	color = julia_color(iter, data->max_iter);
	my_mlx_pixel_put(data, x, y, color);
}

void	draw_julia(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_julia_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
