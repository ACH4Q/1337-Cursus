/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:17:28 by machaq            #+#    #+#             */
/*   Updated: 2024/11/02 18:25:47 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned i;
	char *str;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
    while (i < ft_strlen(s))
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
	str[ft_strlen(s)] = '\0' return (str);
}