/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/01 22:20:29 by machaq           ###   ########.fr       */
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
    while (n != 0)
    {
        n /= 10;
        counter++;
    }
    return (counter);
}
#include <stdio.h>
int main()
{
    printf("%d",number_len(-4234332));
}
 /* char    *ft_itoa(int n)
{
    if (n =)
}
*/
