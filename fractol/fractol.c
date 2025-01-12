/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:38 by machaq            #+#    #+#             */
/*   Updated: 2025/01/11 15:55:59 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    if (!s1 || !s2)
        return -1;
    while (s1[i] || s2[i])
    {
        if (s2[i] != s1[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return 0;
}

void show_menu()
{
    printf("\n=== Fractol Menu ===\n");
    printf("Choose a fractal to render:\n");
    printf("1. mandelbrot\n");
    printf("2. julia\n");
    printf("Type the name of the fractal (or 'exit' to quit):\n");
}

int validate_input(int ac, char **av)
{
    if (ac < 2 || !av[1])
    {
        show_menu();
        return -1;
    }
    if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
        return 0;
    if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
        return 1;

    show_menu();
    return -1;
}

void draw_julia(void *mlx, void *win, double c_re, double c_im) {
    int x = 0, y = 0;

    while (y < 1080)
    {
        x = 0;
        while (x < 1920)
        {
            double z_re = (x - 1920 / 2.0) * 4.0 / 1920;
            double z_im = (y - 1080 / 2.0) * 4.0 / 1080;

            int iter = 0;
            while (z_re * z_re + z_im * z_im <= 4 && iter < 100) {
                double tmp = z_re * z_re - z_im * z_im + c_re;
                z_im = 2 * z_re * z_im + c_im;
                z_re = tmp;
                iter++;
            }
            int color = 0x000000;
            if (iter < 100)
                color = ( 0xFF0000 * iter / 100);
            mlx_pixel_put(mlx, win, x, y, color);
            x++;
        }
        y++;
    }
}

void julia(char *str, char *str1) {
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "Julia");
    double c_re = atof(str);
    double c_im = atof(str1);
    draw_julia(mlx, win, c_re, c_im);
    mlx_loop(mlx);
}

void mandelbrot()
{
   
}

int main(int ac, char **av)
{
    int result = validate_input(ac, av);

    if (result == 0)
        julia(av[2], av[3]);
    else if (result == 1)
        mandelbrot();

    return 0;
}
