/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:07 by machaq            #+#    #+#             */
/*   Updated: 2024/10/30 14:09:23 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char sep)
{
	size_t	words;
	int		i;

	words = 0;
	i = 0;
	while (*str)
	{
		if (*str != sep && !i)
		{
			i = 1;
			words++;
		}
		else if (*str == sep)
		{
			i = 0;
		}
		str++;
	}
	return (words);
}
static char	*str_allocation(char *s1, int start, int end)
{
	char	*str;

	str = (char *)malloc(end - start + 1);
	if (!*str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
char	**ft_split(char const *s, char c)
{
	int		start;
	size_t	i;
	int		word;
	char	**result;
	word = 0;
	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	result = malloc(count_word(s, c) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[word++] = str_allocation((char *)s, start, i + 1);
			if (!result[word - 1])
				return (NULL);
		}
		i++;
	}
	result[word] = NULL;
	return (result);
}
