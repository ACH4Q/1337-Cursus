/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:04 by machaq            #+#    #+#             */
/*   Updated: 2024/10/25 09:46:01 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*char_calloc;

	i = 0;
	char_calloc = malloc(count * size);
	if (!char_calloc)
		return (NULL);
	ft_memset(char_calloc, 0, (count * size));
	return (char_calloc);
}
