/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:37:05 by machaq            #+#    #+#             */
/*   Updated: 2025/01/07 21:55:18 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>

typedef struct t_image 
{   
    int     line;
    int     *image;
    char    *pixels
    int     bits;       

} t_image;

typedef struct t_mlx
{
    void    *windows;
    void    *connection;
}   t_fractal;


#endif