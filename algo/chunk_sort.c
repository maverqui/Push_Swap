/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:00:34 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 16:38:55 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//pos index size
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
//block size by wave 
static	void	chunk_dispatch(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	int		chunk_size;
	int		lst_size;
	int		max;

	chunk_size = 0;
	lst_size = ft_lstsize(*lst_a);
	if (lst_size <= 200)
		chunk_size = 15;
	else
		chunk_size = 30;
	max = chunk_size;
	while(*lst_a)
	{
		if((*lst_a)->index < max)
		{
			pb(lst_a, lst_b, operations);
			if((*lst_b)->index < (max - chunk_size / 2))
				rb(lst_b, operations);
		}
		else
			ra(lst_a, operations);
		if (ft_lstsize(*lst_b) >= max)
			max += chunk_size;
	}
}

static	int find_max_index(t_list *lst_b)
{
	int max;

	max = lst_b->index;
	while(lst_b)
	{
		if (lst_b->index > max)
			max = lst_b->index;
		lst_b = lst_b->next;
	}
	return (max);
}
//search pos max
static	int find_position(t_list *lst_b, int index)
{
	int pos;

	pos = 0;
	while(lst_b)
	{
		if(lst_b->index == index)
			return(pos);
		pos++;
		lst_b = lst_b->next;
	}
	return(-1);
}

static	void	return_to_a(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	int max;
	int pos;

	while (*lst_b)
	{
		max = find_max_index(*lst_b);
		pos = find_position(*lst_b, max);
		if (pos <= ft_lstsize(*lst_b) / 2)
		{
			while ((*lst_b)->index != max)
				rb(lst_b, operations);
		}
		else
		{
			while ((*lst_b)->index != max)
				rrb(lst_b, operations);
		}
		pa (lst_a, lst_b, operations);
	}
}

void	ft_chunk_sort(t_list **lst_a, t_operations *operations)
{
	t_list	*lst_b;

	lst_b = NULL;
	ft_index(lst_a);
	chunk_dispatch(lst_a, &lst_b, operations);
	return_to_a(lst_a, &lst_b, operations);
}