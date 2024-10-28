/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:07 by machaq            #+#    #+#             */
/*   Updated: 2024/10/28 20:53:41 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(const char *s)
{
    while (*s)
    {
        *s++;
    }
    return (s);
}
#include <stdio.h>
int main()
{
    char *name = "imran";
    printf("%d", ft_strlen(name));
    return 0;
}