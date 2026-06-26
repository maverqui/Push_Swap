/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:13:56 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/26 18:26:10 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	int	get_value(t_list *a, int i){
	while (i--)
		a = a->next;
	return (a->value);
}

float	compute_disorder(t_list **lst_a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < ft_lstsize(*lst_a) - 1)
	{
		j = i + 1;
		while (j < ft_lstsize(*lst_a))
		{
			total_pairs++;
			if (get_value(*lst_a, i) > get_value(*lst_a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}

void	adaptive_algo(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	float	disorder;

	disorder = compute_disorder(lst_a);
	if (disorder < 0.2)
		ft_bubble_sort(lst_a, operations);
	else if (disorder <= 0.2 && disorder < 0.5)
		ft_chunk_sort(lst_a, operations);
	else if (disorder >= 0.5)
		ft_radix_sort(lst_a, lst_b, operations);
	return ;
}