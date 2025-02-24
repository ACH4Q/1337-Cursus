/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:26 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/03 16:40:46 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!!lst)
	{
		while (!!(lst->next) && ++i)
			lst = lst->next;
		i += 1;
	}
	return (i);
}

int	put_on_sa(int *arr, int len_arr)
{
	int	index;

	t_list(*stack_a);
	t_list(*stack_b);
	index = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (index < len_arr)
		ft_lstadd_back((&stack_a), ft_lstnew(arr[index++]));
	if (!stack_a)
		return (1);
	while (is_sorted(&stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
