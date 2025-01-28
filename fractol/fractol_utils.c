/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:53:33 by machaq            #+#    #+#             */
/*   Updated: 2025/01/26 10:11:02 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

double	map(double value, t_range from, t_range to)
{
	return (to.min + (value - from.min) * (to.max - to.min) / (from.max
			- from.min));
}

static double	parse_integer(const char *str, int *i)
{
	double	result;

	result = 0.0;
	if (!(*str >= '0' && *str <= '9') && *str != '+' && *str != '-')
		exit(1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_fraction(const char *str, int *i)
{
	double	fraction;
	double	divider;

	fraction = 0.0;
	divider = 10.0;
	if (!(*str >= '0' && *str <= '9') && *str != '+' && *str != '-')
		exit(1);
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction += (str[*i] - '0') / divider;
			divider *= 10.0;
			(*i)++;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	fraction;
	double	final;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
		exit(1);
	sign = check_sign(str, &i);
	result = parse_integer(str, &i);
	fraction = parse_fraction(str, &i);
	final = sign * (result + fraction);
	if (str[i] != '\0' || final < -2.0 || final > 2.0)
		exit(1);
	return (final);
}
