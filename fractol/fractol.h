/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:37:05 by machaq            #+#    #+#             */
/*   Updated: 2025/01/11 15:18:45 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
#include <stdio.h>
#include <unistd.h>

# define WIDTH 1080
# define HEIGHT 1920

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	double		minreal;
	double		maxreal;
	double		min_i;
	double		max_i;
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		max_n;
	int			random;
}				t_data;


void			julia(t_data *data);
void			julia_init(t_data *data);
void			zoom_julia(t_data *data, int mousecode);
int				julia_n(t_data *data);
void ft_putendl(char *str);
int keys(int keycode, t_data *data);
int mouse_hook(int button, int x, int y, t_data *data);

#endif
