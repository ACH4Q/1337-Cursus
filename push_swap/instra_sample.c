/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra_sample.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:13:52 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 16:04:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_list **stack_out, t_list **stack_in, char c)
{
	t_list	*node;

	node = *stack_out;
	if (!*stack_out)
		return ;
	ft_lstadd_front(stack_in, ft_lstnew(node->content));
	*stack_out = (*stack_out)->next;
	free(node);
	if (c)
	{
		ft_printf("p");
		if (c == 'a')
			ft_printf("a\n");
		else if (c == 'b')
			ft_printf("b\n");
	}
}

void	ra_rb(t_list **stack, char c)
{
	t_list	*node1;

	node1 = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_lstadd_back(stack, node1);
	*stack = (*stack)->next;
	node1->next = NULL;
	if (c)
	{
		ft_printf("r");
		if (c == 'a')
			ft_printf("a\n");
		else if (c == 'b')
			ft_printf("b\n");
	}
	give_index(stack);
}

void	rra_rrb(t_list **stack, char c)
{
	t_list(*last);
	t_list(*pre_last);
	(1) && (pre_last = *stack) && (last = *stack);
	if (!*stack || !(*stack)->next)
		return ;
	while (last->next != NULL)
		last = last->next;
	while (1)
	{
		if (pre_last->next->next == NULL)
		{
			pre_last->next = NULL;
			break ;
		}
		pre_last = pre_last->next;
	}
	ft_lstadd_front(stack, last);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	sa_sb(t_list **stack, char c)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (*stack == NULL || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = (*stack)->next;
	node3 = node2->next;
	*stack = node2;
	node2->next = node1;
	node1->next = node3;
	if (c)
	{
		ft_printf("s");
		if (c == 'a')
			ft_printf("a\n");
		else if (c == 'b')
			ft_printf("b\n");
	}
}
