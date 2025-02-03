/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:28:32 by machaq            #+#    #+#             */
/*   Updated: 2025/02/03 15:09:48 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_node *stack)
{
    int max = 0, max_bits = 0;
    
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
    int max_bits = get_max_bits(*stack_a);
    int i = 0, j, pushed;
    t_node *temp;

    while (i < max_bits)
    {
        j = 0;
        pushed = 0;
        while (j < size)
        {
            temp = *stack_a;
            if (((temp->value >> i) & 1) == 0)
            {
                push(stack_a, stack_b, 'b');
                pushed++;
            }
            else
                rotate(stack_a, 'a');
            j++;
        }
        while (pushed > 0)
        {
            push(stack_b, stack_a, 'a');
            pushed--;
        }
        i++;
    }
}
