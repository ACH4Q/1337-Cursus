/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:15:40 by machaq            #+#    #+#             */
/*   Updated: 2024/10/27 17:26:26 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*allocated_str;
	int		i;
	int		j;

    i = 0;
    j = 0;
	allocated_str = (char   *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 && !s2)
		return (NULL);
	while (s1[i])
	{
		allocated_str[i] = s1[i];
		i++;
	}
	allocated_str[i] = '\0';
	while (s2[j])
	{
		allocated_str[i + j] = s2[j];
		j++;
	}
	allocated_str[i + j] = '\0';
	return (allocated_str);
}
#include <stdio.h>
int	main(void)
{
    char    *str = NULL;
    char    *str1 = NULL;
    void *result = ft_strjoin(str,str1);
    printf("%s",result);
}