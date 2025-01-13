/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:25:23 by machaq            #+#    #+#             */
/*   Updated: 2025/01/13 14:45:57 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_mouse(int button, int x, int y, t_data *data)
{
    double mouse_re;
    double mouse_im;

    mouse_re = map(x, 0, WIDTH, -2.0 / data->zoom + data->offset_x, 2.0 / data->zoom + data->offset_x);
    mouse_im = map(y, 0, HEIGHT, -2.0 / data->zoom + data->offset_y, 2.0 / data->zoom + data->offset_y);
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

int handle_key(int keycode, t_data *data)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        data->offset_x -= 0.1 / data->zoom;
    else if (keycode == 124)
        data->offset_x += 0.1 / data->zoom;
    else if (keycode == 126)
        data->offset_y -= 0.1 / data->zoom;
    else if (keycode == 125)
        data->offset_y += 0.1 / data->zoom;
    else if (keycode == 8)
        data->max_iter += 10;
    draw_fractal(data);
    return (0);
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

void signal_handler(int signum)
{
    if (signum == SIGINT || signum == SIGQUIT)
        exit(0);
}