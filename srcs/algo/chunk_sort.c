/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:00:34 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/30 16:45:13 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
//block size by wave 
static	void	chunk_dispatch(t_data *data)
{
	int		chunk_size;
	int		lst_size;
	int		max;

	chunk_size = 0;
	lst_size = ft_lstsize(data->lst_a);
	if (lst_size <= 200)
		chunk_size = 15;
	else
		chunk_size = 30;
	max = chunk_size;
	while (data->lst_a)
	{
		if ((data->lst_a)->index < max)
		{
			pb(&data->lst_a, &data->lst_b, &data->operations);
			if ((data->lst_b)->index < (max - chunk_size / 2))
				rb(&data->lst_b, &data->operations);
		}
		else
			ra(&data->lst_a, &data->operations);
		if (ft_lstsize(data->lst_b) >= max)
			max += chunk_size;
	}
}

static	int	find_max_index(t_list *lst_b)
{
	int	max;

	max = lst_b->index;
	while (lst_b)
	{
		if (lst_b->index > max)
			max = lst_b->index;
		lst_b = lst_b->next;
	}
	return (max);
}

//search pos max
static	int	find_position(t_list *lst_b, int index)
{
	int	pos;

	pos = 0;
	while (lst_b)
	{
		if (lst_b->index == index)
			return (pos);
		pos++;
		lst_b = lst_b->next;
	}
	return (-1);
}

static void	return_to_a(t_data *data)
{
	int	max;
	int	pos;

	while (data->lst_b)
	{
		max = find_max_index(data->lst_b);
		pos = find_position(data->lst_b, max);
		if (pos <= ft_lstsize(data->lst_b) / 2)
		{
			while ((data->lst_b)->index != max)
				rb(&data->lst_b, &data->operations);
		}
		else
		{
			while ((data->lst_b)->index != max)
				rrb(&data->lst_b, &data->operations);
		}
		pa (&data->lst_a, &data->lst_b, &data->operations);
	}
}

void	ft_chunk_sort(t_data *data)
{
	ft_index(&data->lst_a);
	chunk_dispatch(data);
	return_to_a(data);
}
