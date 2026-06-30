/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:31:50 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/30 14:53:37 by maeverqu         ###   ########.fr       */
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

void	ft_bubble_sort(t_data *data)
// void	ft_bubble_sort(t_list **lst_a, t_operations *operations)
{
	int		size;
	int		i;

	if (!data || !(data->lst_a))
		return ;
	size = ft_lstsize(data->lst_a);
	while (!(check_if_sort(data->lst_a)))
	{
		i = 0;
		while (i < size - 1)
		{
			if ((data->lst_a)->value > (data->lst_a)->next->value)
				sa(&data->lst_a, &data->operations);
			ra(&data->lst_a, &data->operations);
			i++;
		}
		ra(&data->lst_a, &data->operations);
	}
}
