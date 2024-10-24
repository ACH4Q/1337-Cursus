/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:08:15 by machaq            #+#    #+#             */
/*   Updated: 2024/10/24 19:15:11 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			char_c;

	i = 0;
	char_c = (char)c;
	while (s[i])
	{
		if (s[i] == char_c)
			return ((char *)&s[i]);
		i++;
	}
	if (char_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	const char	str[] = "Hello, 1337!";
	char		*result;

	// Test: Finding 'e'
	result = ft_strchr(str, 'e');
	if (result)
		printf("Found 'e' at: %s\n", result);
	else
		printf("'e' not found\n");
	// Test: Finding 'z' (which is not in the string)
	result = ft_strchr(str, 'z');
	if (result)
		printf("Found 'z' at: %s\n", result);
	else
		printf("'z' not found\n");
	// Test: Finding the null terminator '\0'
	result = ft_strchr(str, '\0');
	if (result)
		printf("Found null terminator at: %p\n", (void *)result);
	return (0);
}
