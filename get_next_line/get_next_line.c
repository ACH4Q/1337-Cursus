/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:39:11 by machaq            #+#    #+#             */
/*   Updated: 2024/11/27 18:22:32 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char		*buff;
	int			red;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	red = 1;
	while (red != 0)
	{
		red = read (fd, buff, BUFFER_SIZE);
		if (red == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[red] = '\0';
		str = ft_strjoin(str, buff);
		if (check_new_line(str))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = read_file(fd, str);
	ptr = ft_get_line(str);
	str = ft_remove(str);
	return (ptr);
}
