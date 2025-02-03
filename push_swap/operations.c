/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:46 by machaq            #+#    #+#             */
/*   Updated: 2025/02/02 17:27:53 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_node **src, t_node **dest, char stack_name)
{
    if (!*src) return;
    t_node *temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
    if (stack_name == 'a')
        write(1, "pa\n", 3);
    else
        write(1, "pb\n", 3);
}

void swap(t_node **stack, char stack_name)
{
    if (!*stack || !(*stack)->next)
        return;
    t_node *first = *stack;
    t_node *second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    if (stack_name == 'a')
        write(1, "sa\n", 3);
    else
        write(1, "sb\n", 3);
}

void rotate(t_node **stack, char stack_name)
{
    if (!*stack || !(*stack)->next)
        return;
    t_node *first = *stack;
    *stack = (*stack)->next;
    t_node *temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = first;
    first->next = NULL;
    if (stack_name == 'a')
        write(1, "ra\n", 3);
    else
        write(1, "rb\n", 3);
}

void reverse_rotate(t_node **stack, char stack_name)
{
    if (!*stack || !(*stack)->next)
        return;
    t_node *temp = *stack;
    while (temp->next->next)
        temp = temp->next;
    t_node *last = temp->next;
    temp->next = NULL;
    last->next = *stack;
    *stack = last;
    if (stack_name == 'a')
        write(1, "rra\n", 4);
    else
        write(1, "rrb\n", 4);
}
