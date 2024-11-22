/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:49:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/22 21:54:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_static(int fd,char *str)
{
    char    *buffer;
    int     i;

    i = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (i > 0 && ft_strchr(buffer , '\n'))
    {
        i = read(fd,buffer,BUFFER_SIZE);
        if (i <= 0)
        {
            free(buffer);
            return (str);
        }
        buffer[1] = '\0';
        ft_strjoin(str,buffer);
    }
    free (buffer);
    return (str);
}
char    *get_next_line(int fd)
{
    char    static *str;
    char            *buffer;

    if (fd < 0|| BUFFER_SIZE <=0)
        return (NULL);
    str = get_static(fd,str);
    buffer = get_one_line(str);
    str = free_static(str);
    return (buffer);
}