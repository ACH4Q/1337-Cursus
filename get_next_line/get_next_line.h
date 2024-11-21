/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:12:59 by machaq            #+#    #+#             */
/*   Updated: 2024/11/21 23:22:42 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
size_t  ft_strlen(const char *s);
char    get_one_line(char *str);
char	*free_stash(char *str);

#endif