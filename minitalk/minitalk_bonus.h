/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:20:33 by machaq            #+#    #+#             */
/*   Updated: 2025/01/08 13:47:08 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define NUMBIT 0
# define PID 1
# define OTHER_PID 2

void	ft_putnbr(int nb);
int		ft_atoi(char *str);
size_t	ft_strlen(const char *s);

#endif