/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:53:33 by machaq            #+#    #+#             */
/*   Updated: 2025/01/12 11:18:47 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

double map(double value, double min1, double max1, double min2, double max2)
{
    return (min2 + (value - min1) * (max2 - min2) / (max1 - min1));
}

void draw_fractal(t_data *data)
{
    if (data->fractal_type == 1)
        draw_mandelbrot(data);
    else if (data->fractal_type == 2)
        draw_julia(data);
}
