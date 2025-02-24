/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:33 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 20:49:08 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_checker_bonus(int *arr, int len_arr)
{
	int (index), (jndex);
	jndex = 0;
	index = 0;
	while (index < len_arr)
	{
		jndex = index + 1;
		while (jndex < len_arr)
		{
			if (arr[index] == arr[jndex++])
				return (write(2, "Error\n", 6), 1);
		}
		index++;
	}
	return (do_instra(arr, len_arr), 0);
}

int	spt_to_arr_bonus(char ***str, int ac, int str_num)
{
	long	val;

	val = 0;
	int (i), (*arr), (len_arr), (ac_i);
	(1) && (i = 0), (len_arr = 0), (ac_i = 0);
	arr = malloc(sizeof(int) * (str_num));
	if (!arr)
		return (1);
	while (ac_i < ac - 1)
	{
		i = 0;
		while (str[ac_i][i] != NULL)
		{
			val = ft_atoi(str[ac_i][i++]);
			if (val > INT_MAX || val < INT_MIN)
				return (write(2, "Error\n", 6), free(arr), 1);
			arr[len_arr++] = val;
		}
		ac_i++;
	}
	dup_checker_bonus(arr, len_arr);
	return (free(arr), arr = NULL, 1);
}

int	main(int ac, char **av)
{
	int		i;
	char	***str;

	int (str_num), (i_i);
	(1) && (i_i = 0), (i = 1), (str_num = 0);
	if (ac == 1)
		return (1);
	while (i < ac)
	{
		if (ft_atoi_checker(av[i], &str_num))
			return (write(2, "Error\n", 6), 1);
		i++;
	}
	str = malloc((i = 1, sizeof(char **) * ac));
	if (!str)
		return (1);
	while (i < ac)
		str[i_i++] = ft_split(av[i++], ' ');
	spt_to_arr_bonus(str, ac, str_num);
	return (ft_free_sp(str, ac), 0);
}
