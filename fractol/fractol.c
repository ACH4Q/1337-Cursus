/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:38 by machaq            #+#    #+#             */
/*   Updated: 2025/01/04 17:02:15 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    if ((ac == 2 && av[1] == "mandalbrot") || (ac == 4 && av[1] == "julia"))
    {
            t_fractol fractal;
            fractol_init(&fractal);
    }
    else 
    {
        write(1,"Usage ./fractol <Julia / Maldrbrot> <real> <imaginary>",57);
    }
}

