/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:14 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 18:35:03 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	ft_index(t_list **lst)
{
	t_list *actual;
	t_list *to_compare;

	actual = *lst;
	while(actual)
	{
		actual->index = 0;
		to_compare = *lst;
		while(to_compare)
		{
			if (actual->value > to_compare->value)
				actual->index++;
			to_compare = to_compare->next;
		}
		actual = actual->next;
	}
}

