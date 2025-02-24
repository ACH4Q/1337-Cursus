/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:14 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/05 13:40:00 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

// split
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	cal_seg(const char *inp, char cdel)
{
	size_t	seg;
	int		inseg;

	seg = 0;
	inseg = 0;
	seg = 0;
	inseg = 0;
	while (!!*inp)
	{
		if (*inp != cdel && !inseg)
		{
			seg++;
			inseg = 1;
		}
		else if (*inp == cdel)
			inseg = 0;
		inp++;
	}
	return (seg);
}

char	*eseg(const char *start, size_t len)
{
	char	*result;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, start, len);
	return (*(result + len) = '\0', result);
}

char	**spseg(const char *inp, char del, char **res)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*inp)
	{
		if (*inp != del)
		{
			start = inp;
			while (*inp && *inp != del)
				inp++;
			res[i] = eseg(start, inp - start);
			if (!res[i])
			{
				while (i--)
					free(res[i]);
				return (free(res), NULL);
			}
			i++;
		}
		else if (*inp == del)
			inp++;
	}
	return (res[i] = NULL, res);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	tsegs;

	tsegs = cal_seg(s, c);
	result = (char **)malloc((tsegs + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (spseg(s, c, result));
}
