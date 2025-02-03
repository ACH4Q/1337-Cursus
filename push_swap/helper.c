/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:09:23 by machaq            #+#    #+#             */
/*   Updated: 2025/02/03 15:09:28 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack)
{
    int a, b, c;
    t_node *temp;

    while (!is_sorted(*stack))
    {
        temp = *stack;
        a = temp->value;
        b = temp->next->value;
        c = temp->next->next->value;

        if (a > b && b < c && a < c)
            swap(stack, 'a'); // sa
        else if (a > b && b > c)
        {
            swap(stack, 'a'); // sa
            reverse_rotate(stack, 'a'); // rra
        }
        else if (a > b && b < c)
            rotate(stack, 'a'); // ra
        else if (a < b && b > c && a < c)
        {
            swap(stack, 'a'); // sa
            rotate(stack, 'a'); // ra
        }
        else if (a < b && b > c)
            reverse_rotate(stack, 'a'); // rra
    }
}

void small_sort(t_node **stack_a, t_node **stack_b, int size)
{
    while (size > 3)
    {
        push(stack_a, stack_b, 'b');
        size--;
    }
    sort_three(stack_a);
    
    while (*stack_b)
        push(stack_b, stack_a, 'a');
}
