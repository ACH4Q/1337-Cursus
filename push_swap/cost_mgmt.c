/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:27:27 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 15:29:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_cost(t_list **stack)
{
	t_list	*temp1;

	give_index(stack);
	temp1 = *stack;
	while (temp1)
	{
		if (temp1->index <= ft_lstsize(*stack) / 2)
			temp1->cost = temp1->index;
		else
			temp1->cost = ft_lstsize(*stack) - temp1->index;
		temp1 = temp1->next;
	}
}

void	give_cost_total(t_list **stack_b)
{
	t_list	*temp1;

	temp1 = *stack_b;
	while (temp1)
	{
		temp1->cost_total = temp1->cost + temp1->target->cost;
		temp1 = temp1->next;
	}
}

void	cal_cost(t_list *node, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (node->target->med == 1)
		cost_a = node->target->index;
	else
		cost_a = size_a - node->target->index;
	if (node->med == 1)
		cost_b = node->index;
	else
		cost_b = size_b - node->index;
	if (node->target->med == node->med)
	{
		if (cost_a > cost_b)
			node->cost_total = cost_a;
		else
			node->cost_total = cost_b;
	}
	else
		node->cost_total = cost_a + cost_b;
}

void	cheapst_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*cheap;

	tmp = *stack_b;
	cheap = tmp;
	while (tmp)
	{
		cal_cost(tmp, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (tmp->cost_total < cheap->cost_total)
			cheap = tmp;
		tmp = tmp->next;
	}
	sb_to_sa(stack_a, stack_b, cheap);
}
