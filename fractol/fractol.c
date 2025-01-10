/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:38 by machaq            #+#    #+#             */
/*   Updated: 2025/01/10 18:41:45 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
    if (!s1 && !s2)
    {
	    while (s1[i] || s2[i])
	    {
		    if (s2[i] != s1[i])
		    	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		    i++;
	    }
    }
	return (0);
}

void show_menu()
{
    printf("\n=== Fractol Menu ===\n");
    printf("Choose a fractal to render:\n");
    printf("1. mandelbrot\n");
    printf("2. julia\n");
    printf("Type the name of the fractal (or 'exit' to quit): ");
}

int validate_input(int ac, char **av) 
{
    if (ac < 2 || av[1] == NULL) {
        show_menu();
        return -1;
    }
    if (strcmp(av[1], "julia") == 0 && ac >= 2 && ac <= 4)
        return 0;
    if (strcmp(av[1], "mandelbrot") == 0 && ac == 2)
        return 1;

    show_menu();
    return -1;
}

void window_initialise(const char *title)
{
    void *mlx;
    void *mlx_win;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, title);
    mlx_loop(mlx);
}

void julia()
{
    window_initialise("Julia");
}

void mandelbrot()
{
    window_initialise("Mandelbrot");
}

int main(int ac, char **av) {
    int result = validate_input(ac, av);
    if (result == 0)
        julia();
    else if (result == 1)
        mandelbrot();
    return 0;
}
