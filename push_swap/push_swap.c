/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:09:01 by machaq            #+#    #+#             */
/*   Updated: 2025/02/03 15:09:04 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    int size = argc - 1;

    if (argc < 2)
        return (0);
    
    stack_a = init_stack(argc, argv);
    
    if (!stack_a || is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }

    if (size == 2)
        swap(&stack_a, 'a');
    else if (size == 3)
        sort_three(&stack_a);
    else if (size <= 5)
        small_sort(&stack_a, &stack_b, size);
    else
        radix_sort(&stack_a, &stack_b, size);

    free_stack(&stack_a);
    return (0);
}
