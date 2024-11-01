/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/01 22:16:08 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int number_len(int n)
{
    int counter;
    if(n < 0)
        counter -= counter;
    if (n == 0)
        counter = 1;
    while (n != 0)
    {
        n /= n;
        counter++;
    }
    return (counter);
}
int main()
{
    number_len(423432);
}
 /* char    *ft_itoa(int n)
{
    if (n =)
}
*/
