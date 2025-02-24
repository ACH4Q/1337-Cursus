/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:44 by mhaddou           #+#    #+#             */
/*   Updated: 2025/01/31 10:29:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int		max;
	t_list	*tmp;

	if (ft_lstsize(*stack_a) != 3)
		return ;
	max = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	if (max == (*stack_a)->content)
		ra_rb(stack_a, 'a');
	else if (max == (*stack_a)->next->content)
		rra_rrb(stack_a, 'a');
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa_sb(stack_a, 'a');
}

int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	move_to_top(t_list **stack, t_list *node, char c)
{
	int		pos;
	t_list	*tmp;
	int		size;

	pos = 0;
	tmp = *stack;
	while (tmp && tmp != node)
	{
		pos++;
		tmp = tmp->next;
	}
	size = ft_lstsize(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra_rb(stack, c);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra_rrb(stack, c);
	}
}

void	sort_five(t_list **sa, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*small;
	int		i;

	i = 0;
	while (i < 2)
	{
		tmp = *sa;
		small = tmp;
		while (tmp)
		{
			if (tmp->rank < small->rank)
				small = tmp;
			tmp = tmp->next;
		}
		move_to_top(sa, small, 'a');
		pa_pb(sa, stack_b, 'b');
		i++;
	}
	sort_three(sa);
	pa_pb(stack_b, sa, 'a');
	pa_pb(stack_b, sa, 'a');
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	give_rank(stack_a);
	give_index(stack_a);
	if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 2)
		ra_rb(stack_a, 'a');
	else
		sort_more(stack_a, stack_b);
}
