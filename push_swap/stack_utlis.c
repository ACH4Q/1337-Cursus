/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:30 by machaq            #+#    #+#             */
/*   Updated: 2025/02/02 17:27:40 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *init_stack(int argc, char **argv)
{
    t_node *stack = NULL;
    t_node *new;
    int i = 1;

    while (i < argc)
    {
        if (!is_valid_input(argv[i]))
            error_exit();
        new = malloc(sizeof(t_node));
        if (!new)
            return (NULL);
        new->value = atoi(argv[i]);
        new->next = stack;
        stack = new;
        i++;
    }
    return (stack);
}

void free_stack(t_node **stack)
{
    t_node *temp;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
