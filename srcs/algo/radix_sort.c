/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorossel <jorossel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:14 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/28 17:31:15 by jorossel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//pos index size
void	ft_index(t_list **lst)
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

int	find_max_bits(int n)
{
	int	power;
	int	res;
	
	power = 0;
	res = 1;
	while (res <= n)
	{
		res = res * 2;
		power++;
	}
	return (power);
}

void	ft_radix_sort(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	int		i;
	int		j;
	int		max_bits;
	int		size;

	ft_index(lst_a);
	size = ft_lstsize(*lst_a);
	max_bits = find_max_bits(size - 1);
	i = 0;
	while (i < max_bits)	
	{
		j = 0;
		while (j < size)
		{
			if ((((*lst_a)->index >> i) & 1) == 0)
				pb(lst_a, lst_b, operations);
			else
				ra(lst_a, operations);
			j++;
		}
		while (*lst_b)
			pa(lst_a, lst_b, operations);
		i++;
	}
}

