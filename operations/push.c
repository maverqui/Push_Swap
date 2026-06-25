/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:36:58 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 16:34:09 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (!(*src) || !src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	ft_push(lst_b, lst_a);
	write(1, "pa\n", 3);
	operations->pa += 1;
}

void	pb(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	ft_push(lst_a, lst_b);
	write(1, "pb\n", 3);
	operations->pb += 1;
}
