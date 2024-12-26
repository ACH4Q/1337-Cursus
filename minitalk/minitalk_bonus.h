/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:20:33 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 11:20:45 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>

void        ft_sender(__pid_t pid, char c);
void        ft_putchar(char c);
void        ft_putstr(char *s);
int         ft_power(int nb, int power);
void        ft_putnbr(int n);
int         ft_atoi(const char *str);


#endif