/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:38 by machaq            #+#    #+#             */
/*   Updated: 2025/01/23 16:46:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parsing_mandelbrot(t_data *data)
{
	data->fractal_type = 1;
	data->c_re = 0;
	data->c_im = 0;
}

void	parsing_julia(t_data *data, int argc, char **argv)
{
	data->fractal_type = 2;
	if (argc == 4)
	{
		data->c_re = ft_atof(argv[2]);
		data->c_im = ft_atof(argv[3]);
	}
	else if (argc == 2)
	{
		data->c_re = -0.7;
		data->c_im = 0.27015;
	}
	else
		exit (1);
}

void	parsing_burning_ship(t_data *data)
{
	data->fractal_type = 3;
}

void	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 4)
	{
		ft_printf("Usage: ./fractol <fractal_type> [parameters]\n");
		ft_printf("Available fractals: mandelbrot, julia, burning_ship\n");
		exit(1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
	{
		parsing_mandelbrot(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		parsing_julia(data, argc, argv);
	}
	else if (ft_strcmp(argv[1], "burning_ship") == 0 && argc == 2)
	{
		parsing_burning_ship(data);
	}
	else
	{
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	parse_arguments(argc, argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	initialize_data(&data);
	draw_fractal(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
