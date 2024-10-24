/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:13:02 by machaq            #+#    #+#             */
/*   Updated: 2024/10/24 09:13:52 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_tmp;
	const char	*src_tmp;
        
	if (dst == NULL  && src == NULL)
		return (dst);
	if ((src < dst) && (char *)src + n > (char *)dst)
		return (NULL);
	dst_tmp = (char *)dst;
	src_tmp = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}
