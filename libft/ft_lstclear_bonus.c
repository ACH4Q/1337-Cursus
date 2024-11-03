/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:15:39 by machaq            #+#    #+#             */
/*   Updated: 2024/11/03 20:32:40 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_list;

	if (!*lst || !tmp_list)
		return (NULL);
	while (!*lst)
	{
		tmp_list = (*lst)->next;
		del((*lst)->content);
		free(lst);
		tmp_list = *lst;
	}
	*lst = NULL;
}
