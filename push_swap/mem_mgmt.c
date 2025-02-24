/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:37:21 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 18:37:44 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **str)
{
	t_list	*ptr;

	if (!str)
		return ;
	while (*str)
	{
		ptr = (*str)->next;
		free(*str);
		(*str) = ptr;
	}
}

void	ft_free_sp(char ***str, int ac)
{
	int	ac_i;
	int	i;

	ac_i = 0;
	i = 0;
	while (ac_i < ac - 1)
	{
		i = 0;
		while (str[ac_i][i])
			free(str[ac_i][i++]);
		free(str[ac_i++]);
	}
	free(str);
}
