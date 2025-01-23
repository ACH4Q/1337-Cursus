/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:25:23 by machaq            #+#    #+#             */
/*   Updated: 2025/01/23 13:59:00 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map(x, (t_range){0, WIDTH}, (t_range){-2.0 / data->zoom
			+ data->offset_x, 2.0 / data->zoom + data->offset_x});
	mouse_im = map(y, (t_range){0, HEIGHT}, (t_range){-2.0 / data->zoom
			+ data->offset_y, 2.0 / data->zoom + data->offset_y});
	if (button == 4)
	{
		data->zoom *= 1.1;
		data->offset_x += (mouse_re - data->offset_x) * 0.1;
		data->offset_y += (mouse_im - data->offset_y) * 0.1;
	}
	else if (button == 5)
	{
		data->zoom /= 1.1;
		data->offset_x -= (mouse_re - data->offset_x) * 0.1;
		data->offset_y -= (mouse_im - data->offset_y) * 0.1;
	}
	draw_fractal(data);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361)
		data->offset_x -= 0.1 / data->zoom;
	else if (keycode == 65363)
		data->offset_x += 0.1 / data->zoom;
	else if (keycode == 65364)
		data->offset_y -= 0.1 / data->zoom;
	else if (keycode == 65362)
		data->offset_y += 0.1 / data->zoom;
	else if (keycode == 32)
		data->max_iter += 10;
	draw_fractal(data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	draw_fractal(t_data *data)
{
	if (data->fractal_type == 1)
		draw_mandelbrot(data);
	else if (data->fractal_type == 2)
		draw_julia(data);
	else if (data->fractal_type == 3)
		draw_burning_ship(data);
	else
		ft_printf("Invalid fractal type. Unable to draw.\n");
}
