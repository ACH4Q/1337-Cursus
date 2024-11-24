/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:58:14 by machaq            #+#    #+#             */
/*   Updated: 2024/11/24 21:30:41 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p && *p != (char)c)
		++p;
	if (*p == (char)c)
		return (p);
	return ((void *)0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		++i;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*get_one_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_static(char *str)
{
	char *buffer;
	int i;
	int j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		++i;
	if (!str[i] || (str[i] == '\n' && str[i + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	buffer = malloc((ft_strlen(str) - i));
	if (!buffer)
		return (NULL);
	if (buffer)
	{
		while (str[++i])
			buffer[j++] = str[i];
		buffer[j] = '\0';
	}
	free(str);
	return (buffer);
}