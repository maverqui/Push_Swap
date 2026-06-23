/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:31:50 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/17 20:41:34 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bubble_sort(t_list **stack_a)
{
	int		size;
	int		i; // relance la boucle j
	int		j; // range + grand nb
	
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{	
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
			ra(stack_a);
			j++;
		}
		ra(stack_a);
		i++;
	}
}