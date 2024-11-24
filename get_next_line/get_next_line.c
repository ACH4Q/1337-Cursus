/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:49:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/24 19:14:11 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_static(int fd, char *str)
{
    char *buffer;
    char *temp;
    int i;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    i = 1;
    while (i > 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i <= 0)
            break;
        buffer[i] = '\0';
        temp = ft_strjoin(str, buffer);
        free(str);
        str = temp;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (str);
}

char    *get_next_line(int fd)
{
    char        *buffer;
    static char *str[1024];

    if (fd < 0|| BUFFER_SIZE <=0)
        return (NULL);
    str = get_static(fd,str);
    buffer = get_one_line(str[fd]);
    str[fd] = free_static(str[fd]);
    return (buffer);
}