/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:31:50 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/29 18:50:02 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_if_sort(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_bubble_sort(t_list **lst_a, t_operations *operations)
{
	int		size;
	int		i;

	if (!lst_a || !(*lst_a))
		return ;
	size = ft_lstsize(*lst_a);
	while (!(check_if_sort(*lst_a)))
	{
		i = 0;
		while (i < size - 1)
		{
			if ((*lst_a)->value > (*lst_a)->next->value)
				sa(lst_a, operations);
			ra(lst_a, operations);
			i++;
		}
		ra(lst_a, operations);
	}
}
