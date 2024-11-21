/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:58:14 by machaq            #+#    #+#             */
/*   Updated: 2024/11/21 21:17:57 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*allocated_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	allocated_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!allocated_str)
		return (NULL);
	while (s1)
		*allocated_str++ = *s1++;
	free (s1);
	while (s2)
		*allocated_str++ = *s2++;
	free (s2);
	return (allocated_str);
}

size_t	ft_strlen(const char *s)
{
	size_t counter;
	
	if (!s)
		return (NULL);
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
