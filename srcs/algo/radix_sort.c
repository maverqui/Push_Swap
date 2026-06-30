/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:14 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/30 14:53:43 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//pos index size
void	ft_index(t_list **lst)
{
	t_list	*actual;
	t_list	*to_compare;

	actual = *lst;
	while (actual)
	{
		actual->index = 0;
		to_compare = *lst;
		while (to_compare)
		{
			if (actual->value > to_compare->value)
				actual->index++;
			to_compare = to_compare->next;
		}
		actual = actual->next;
	}
}

static int	find_max_bits(int n)
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

void	ft_radix_sort(t_data *data)
{
	int		i;
	int		j;
	int		max_bits;
	int		size;

	ft_index(&data->lst_a);
	size = ft_lstsize(data->lst_a);
	max_bits = find_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((data->lst_a)->index >> i) & 1) == 0)
				pb(&data->lst_a, &data->lst_b, &data->operations);
			else
				ra(&data->lst_a, &data->operations);
			j++;
		}
		while (data->lst_b)
			pa(&data->lst_a, &data->lst_b, &data->operations);
		i++;
	}
}
