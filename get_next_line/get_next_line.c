/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:49:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/22 19:39:56 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_static(int fd,char *static)
{
    char    *buffer;
    int     i;

    i = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (i && ft_strchr(buffer , ))
    {
        i = read(fd,buffer,BUFFER_SIZE);
        
    }
}
char    *get_next_line()