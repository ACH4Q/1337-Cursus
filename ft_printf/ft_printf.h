/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:06:10 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 08:39:54 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF.H
# define FT_PRINTF.H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *s, ...);
int ft_putstr(const char *s);
int ft_printfhex(unsigned long adress,const char *s);
int ft_putnb(int nb);
int ft_putchar(char c);
int ft_printfunsnb(unsigned int i);

#endif