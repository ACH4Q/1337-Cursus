/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:53:46 by machaq            #+#    #+#             */
/*   Updated: 2025/01/12 11:19:41 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_julia(t_data *data)
{
    int     x;
    int     y;
    double  z_re;
    double  z_im;
    int     iter;
    double  tmp;
    int     color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            z_re = map(x, 0, WIDTH, -2.0 / data->zoom + data->offset_x, 2.0 / data->zoom + data->offset_x);
            z_im = map(y, 0, HEIGHT, -2.0 / data->zoom + data->offset_y, 2.0 / data->zoom + data->offset_y);
            iter = 0;
            while ((z_re * z_re + z_im * z_im <= 4) && (iter < data->max_iter))
            {
                tmp = z_re * z_re - z_im * z_im + data->c_re;
                z_im = 2 * z_re * z_im + data->c_im;
                z_re = tmp;
                iter++;
            }
            int shift = data->max_iter % 255;
            if (iter == data->max_iter)
                color = 0x000000;
            else
                color = ((iter * 255 / data->max_iter) + shift) << 16;
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
