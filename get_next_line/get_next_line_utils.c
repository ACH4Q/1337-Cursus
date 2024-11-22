/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:58:14 by machaq            #+#    #+#             */
/*   Updated: 2024/11/22 21:52:44 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *allocated_str;
    size_t i, j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (strdup(s2)); 
    if (!s2)
        return (strdup(s1));
    allocated_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!allocated_str)
        return (NULL);
    i = -1;
    while (s1[++i])
        allocated_str[i] = s1[i];
    j = 0;
    while (s2[j])
        allocated_str[i++] = s2[j++];
    allocated_str[i] = '\0';
    return (allocated_str);
}

size_t	ft_strlen(const char *s)
{
	size_t counter;
	
	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s++;
		counter++;
	}
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			char_c;

	i = 0;
	char_c = (char)c;
	while (s[i])
	{
		if (s[i] == char_c)
			return ((char *)&s[i]);
		i++;
	}
	if (char_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char *get_one_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	while (str && *str++ != '\n')
		i++;
	line = malloc(i + 2);
	while (str && *str++ != '\n')
		*line++ = *str++;
	if (*str == '\n')
		*line++ = '\n';
	*line++ == '\0';
	return (line);	
}

char	*free_static(char *str)
{
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] == '\n')
		i++;
	if (!str[i] || str[i] == '\n' && str[i + 1] == '\0')
	{
		free (str);
		return (NULL);
	}
	str2 = malloc((ft_strlen(str) - i));
	if (str2)
	{
		while (str[++i])
			str2[j++] = str[i];
		str2[j] = '\0';
	}
	free(str);
	return (str2);
}