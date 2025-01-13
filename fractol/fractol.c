/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:38 by machaq            #+#    #+#             */
/*   Updated: 2025/01/13 14:45:28 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void initialize_data(t_data *data)
{
    data->zoom = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;
    data->max_iter = 50;
}

void parse_arguments(int argc, char **argv, t_data *data)
{
    if (argc < 2)
    {
        printf("Usage: %s <fractal_type> [parameters]\n", argv[0]);
        printf("Available fractals: mandelbrot, julia\n");
        exit(1);
    }
    if (strcmp(argv[1], "mandelbrot") == 0)
    {
        data->fractal_type = 1;
        if (argc == 4)
        {
            data->c_re = atof(argv[2]);
            data->c_im = atof(argv[3]);
        }
        else
        {
            data->c_re = 0;
            data->c_im = 0;
        }
    }
    else if (strcmp(argv[1], "julia") == 0)
    {
        data->fractal_type = 2;
        if (argc == 4)
        {
            data->c_re = atof(argv[2]);
            data->c_im = atof(argv[3]);
        }
        else
        {
            data->c_re = -0.7;
            data->c_im = 0.27015;
        }
    }
    else
    {
        printf("Invalid fractal type. Use 'mandelbrot' or 'julia'.\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract'ol");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    initialize_data(&data);
    parse_arguments(argc, argv, &data);
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    draw_fractal(&data);
    mlx_key_hook(data.win, handle_key, &data);
    mlx_mouse_hook(data.win, handle_mouse, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    return (0);
}
