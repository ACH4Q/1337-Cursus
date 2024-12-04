/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:04:47 by machaq            #+#    #+#             */
/*   Updated: 2024/12/04 16:03:40 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putstr(const char *s);
int	ft_printhex(unsigned long adress, const char *base, char flag);
int	ft_printnb(int nb, char flag);
int	ft_putchar(char c);
int	ft_printunsnb(unsigned int i);
int	handle_string(const char *str);
int	handle_pointer(unsigned long address);
int	checker(char spec, va_list args, char flag);

#endif