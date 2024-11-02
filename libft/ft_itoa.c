/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/02 17:46:35 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int number_len(int n)
{
    int counter;

    counter = 0;
    if(n < 0)
    {
        counter++;
        n = -n;
    }
    if (n == 0)
        counter++;
    while (n > 0)
    {
        n /= 10;
        counter++;
    }
    return (counter);
}

char    *ft_itoa(int n)
{
    int i;
    long long j;

    j = n;
    char *str = malloc((number_len(j) + 1)* sizeof(char));
        if (!str)
            return (NULL);
        if (j < 0)
        {
           str[0] = '-';
           j = -j;
        }
        if (j == 0)
            str[0] = '0';
        i = number_len(n) - 1;
        while (j > 0)
        {
            str[i--] = (j % 10) + 48;
            j /= 10;
        }
        str[number_len(j)] = '\0';
        return(str);
}
