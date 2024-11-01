/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:07 by machaq            #+#    #+#             */
/*   Updated: 2024/11/01 18:27:53 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char sep)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (*str == sep)
		{
			in_word = 0;
		}
		str++;
	}
	return (words);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*str_alloc(const char *s, int start, int end)
{
	char	*str;

	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, end - start + 1);
	return (str);
}

static int	fill_words(char **result,char sep,char *s)
{
	size_t	start;
	size_t	i;
	int	word;
	
	i = 0;
	start = 0;
	word = 0;
	while (s[i])
		{
			if (s[i] != sep && (i == 0 || s[i - 1] == sep))
				start = i;
			if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			{
				result[word] = str_alloc(s, start, i + 1);
				if (!result[word])
					return (ft_free(result, word));
				word++;
			}
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char sep)
{
	size_t	words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, sep);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_words(result,sep,s);
		if (!fill_words(result,sep,s))
			return (NULL);
	result[words] = NULL;
	return (result);
}
