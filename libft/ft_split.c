/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:07 by machaq            #+#    #+#             */
/*   Updated: 2024/10/29 19:36:11 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
	
static  size_t count_word(const char *str, char sep)
{
       	size_t words;
		int i;

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
static  char *str_allocation(char   *s, int start, int end)
{
    char *str = (char *)malloc(end - start + 1);
    if (!*str)
        return (NULL);
    ft_strlcpy(str,s,ft_strlen(s));
    return (str);
}



