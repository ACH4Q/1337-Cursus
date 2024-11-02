/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/02 18:00:35 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*char_calloc;

	i = 0;
	if (count != 0 && SIZE_MAX / size < count)
		return (0);
	char_calloc = malloc(count * size);
	if (!char_calloc)
		return (NULL);
	ft_bzero(char_calloc, (count * size));
	return (char_calloc);
}
