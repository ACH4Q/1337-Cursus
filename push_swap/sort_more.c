/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:21 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 11:31:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_to_sb(t_list **stack_a, t_list **stack_b)
{
	int	val;

	while (ft_lstsize(*stack_a) > 3)
	{
		val = ft_lstsize(*stack_a) / 3;
		give_rank(stack_a);
		if ((*stack_a)->rank <= val)
			pa_pb(stack_a, stack_b, 'b');
		else
			ra_rb(stack_a, 'a');
	}
}

void	give_med(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index <= ft_lstsize(tmp) / 2)
			tmp->med = 1;
		else if (tmp->index > ft_lstsize(tmp) / 2)
			tmp->med = 3;
		tmp = tmp->next;
	}
}

void	sb_to_sa(t_list **stack_a, t_list **stack_b, t_list *cheap)
{
	while (cheap->target->med == cheap->med
		&& (*stack_a)->content != cheap->target->content
		&& (*stack_b)->content != cheap->content)
	{
		if (cheap->med == 1)
			rr(stack_a, stack_b, 'a');
		else
			rrr(stack_a, stack_b, 'a');
	}
	while ((*stack_a)->content != cheap->target->content)
	{
		if (cheap->target->med == 1)
			ra_rb(stack_a, 'a');
		else
			rra_rrb(stack_a, 'a');
	}
	while ((*stack_b)->content != cheap->content)
	{
		if (cheap->med == 1)
			ra_rb(stack_b, 'b');
		else
			rra_rrb(stack_b, 'b');
	}
	pa_pb(stack_b, stack_a, 'a');
}

void	put_on_h(t_list **stack_a)
{
	t_list	*tmp;
	int		size;
	int		pos;

	give_rank(stack_a);
	give_index(stack_a);
	size = ft_lstsize(*stack_a);
	tmp = *stack_a;
	pos = 0;
	while (tmp && tmp->rank != 1)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			ra_rb(stack_a, 'a');
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra_rrb(stack_a, 'a');
	}
}

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
		sa_to_sb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	while (ft_lstsize(*stack_a) != len)
	{
		give_index(stack_a);
		give_index(stack_b);
		give_rank(stack_a);
		give_rank(stack_b);
		give_med(stack_b);
		give_med(stack_a);
		give_target(stack_a, stack_b);
		give_cost(stack_b);
		give_cost(stack_a);
		give_cost_total(stack_b);
		cheapst_cost(stack_a, stack_b);
	}
	if (is_sorted(stack_a))
		put_on_h(stack_a);
}
