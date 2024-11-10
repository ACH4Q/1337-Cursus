/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/06 00:15:19 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*char_calloc;

	if (count != 0 && SIZE_MAX / count < size)
		return (NULL);
	char_calloc = malloc(count * size);
	if (!char_calloc)
		return (NULL);
	ft_bzero(char_calloc, count * size);
	return (char_calloc);
}
