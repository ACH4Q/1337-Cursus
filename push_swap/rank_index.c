/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:38 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 21:52:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_list **stack)
{
	t_list	*temp;
	int		index;

	temp = *stack;
	index = 1;
	while (temp != NULL)
	{
		temp->index = index;
		temp = temp->next;
		index++;
	}
}

void	give_rank(t_list **stack_a)
{
	t_list	*tmp1;
	int		rank;
	t_list	*tmp2;

	tmp1 = *stack_a;
	while (tmp1)
	{
		rank = 1;
		tmp2 = *stack_a;
		while (tmp2)
		{
			if (tmp1->content > tmp2->content)
				rank++;
			tmp2 = tmp2->next;
		}
		tmp1->rank = rank;
		tmp1 = tmp1->next;
	}
}

void	complete_it(t_list *temp1, t_list *temp2, int flag)
{
	if (!flag)
	{
		temp2->target = temp1;
		while (temp1)
		{
			if (temp1->content < temp2->target->content)
				temp2->target = temp1;
			temp1 = temp1->next;
		}
	}
}

void	give_target(t_list **stack_a, t_list **stack_b)
{
	long (nb);
	t_list (*temp1);
	t_list (*temp2);
	(1) && (temp1 = *stack_a, temp2 = *stack_b);
	int (bigger), (flag);
	while (temp2)
	{
		(1) && (temp1 = *stack_a, bigger = -1, temp2->target = temp1);
		(1) && (nb = LONG_MAX, flag = 0);
		while (temp1)
		{
			if (temp1->content > temp2->content && temp1->content < nb)
				(1) && (flag = 1, nb = temp1->content, temp2->target = temp1);
			temp1 = temp1->next;
		}
		temp1 = *stack_a;
		complete_it(temp1, temp2, flag);
		temp2 = temp2->next;
	}
}
