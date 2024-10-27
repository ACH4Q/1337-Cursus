/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:40:36 by machaq            #+#    #+#             */
/*   Updated: 2024/10/27 17:47:59 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int i;
	int j;

	i = 0;
	void *allocated_str = (char *)malloc(ft_strlen(s1) + 1);
	while (s1)
	{
		allocated_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (allocated_str)
	{
		if (set[i] = allocated_str[i])
		{
			ft_calloc(1, 1);
			j--;
		}
		i++;
	}
	 allocated_str[i] = '\0';
     return (allocated_str);
}