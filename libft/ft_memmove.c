/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:43:13 by machaq            #+#    #+#             */
/*   Updated: 2024/11/07 21:03:31 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src_tmp;
	char	*dst_tmp;

	if (!dst && !src)
		return (NULL);
	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = 0;
	if (dst_tmp > src_tmp)
	{
		while (len-- > 0)
		{
			dst_tmp[len] = src_tmp[len];
		}
	}
	else
	{
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
