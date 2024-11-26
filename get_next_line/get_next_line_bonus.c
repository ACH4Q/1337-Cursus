/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:38:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/26 14:13:05 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *str)
{
	char		buff[BUFFER_SIZE + 1];
	int			red;

	red = 1;
	while (red != 0)
	{
		red = read (fd, buff, BUFFER_SIZE);
		if (red == -1)
		{
			free(str);
			return (NULL);
		}
		buff[red] = '\0';
		str = ft_strjoin(str, buff);
		if (check_new_line(str))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	ptr = ft_get_line(str[fd]);
	str[fd] = ft_remove(str[fd]);
	return (ptr);
}
