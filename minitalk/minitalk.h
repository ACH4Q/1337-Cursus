/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:17:37 by machaq            #+#    #+#             */
/*   Updated: 2024/12/29 09:59:40 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define NUMBIT 0
# define PID 1
# define OTHER_PID 2

void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif