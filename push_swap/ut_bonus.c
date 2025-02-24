/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:32:04 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 20:41:41 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((char *)s1)[index] != ((char *)s2)[index])
		{
			return (((char *)s1)[index] - ((char *)s2)[index]);
		}
		index++;
	}
	return (0);
}

int	do_swap(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_memcmp(line, "sa\n", 2) == 0)
		sa_sb(stack_a, 0);
	else if (ft_memcmp(line, "sb\n", ft_strlen(line)) == 0)
		sa_sb(stack_b, 0);
	else if (ft_memcmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_memcmp(line, "pa\n", ft_strlen(line)) == 0)
		pa_pb(stack_b, stack_a, 0);
	else if (ft_memcmp(line, "pb\n", ft_strlen(line)) == 0)
		pa_pb(stack_a, stack_b, 0);
	else if (ft_memcmp(line, "ra\n", ft_strlen(line)) == 0)
		ra_rb(stack_a, 0);
	else if (ft_memcmp(line, "rb\n", ft_strlen(line)) == 0)
		ra_rb(stack_b, 0);
	else if (ft_memcmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_memcmp(line, "rra\n", ft_strlen(line)) == 0)
		rra_rrb(stack_a, 0);
	else if (ft_memcmp(line, "rrb\n", ft_strlen(line)) == 0)
		rra_rrb(stack_b, 0);
	else if (ft_memcmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(stack_a, stack_b, 0);
	else if (*line)
		return (write(2, "Error\n", 6), 1);
	return (0);
}

int	do_instra(int *arr, int len_arr)
{
	char	*line;

	int (index), (size);
	t_list(*stack_a);
	t_list(*stack_b);
	(1) && (size = 0), (index = 0), (stack_a = NULL), (stack_b = NULL);
	while (index < len_arr)
		ft_lstadd_back((&stack_a), ft_lstnew(arr[index++]));
	size = ft_lstsize(stack_a);
	if (!stack_a)
		return (1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (do_swap(&stack_a, &stack_b, line))
			return (free(line), free_stack(&stack_a), free_stack(&stack_b), 1);
		free(line);
	}
	if (!is_sorted(&stack_a) && !stack_b)
		return (write(1, "OK\n", 3), free_stack(&stack_a), 0);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 1);
}
