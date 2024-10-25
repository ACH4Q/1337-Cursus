/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:04 by machaq            #+#    #+#             */
/*   Updated: 2024/10/25 09:35:30 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*char_calloc;

	i = 0;
	char_calloc = malloc(count * size);
	while (i < count * size)
	{
		char_calloc[i++] = 0;
	}
	return (char_calloc);
}
