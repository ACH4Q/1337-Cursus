/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:40:36 by machaq            #+#    #+#             */
/*   Updated: 2024/10/28 20:14:21 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	end;
	size_t	start;
	char	*str_allocated;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (start < end && ft_strchr(set,s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set,s1[end]))
	{
		end--;
	}
	str_allocated = (char *)(malloc( (end - start  + 1)));
	if (!str_allocated)
		return (NULL);
	ft_strlcpy(str_allocated,s1 + start,end - start + 1);
	return (str_allocated);
}
#include <stdio.h>
int	main()
{
	char *str = "ddddfffffACH4Qfdfdfdfdf";
	char *s = "df";
	printf("%s",ft_strtrim(str,s));
}
