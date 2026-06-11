/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:43:04 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/11 13:21:43 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void ft_swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (!lst || !(*lst) || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	(*lst) = second;
}

void	sa(t_list **lst_a)
{
	ft_swap(lst_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **lst_b)
{
	ft_swap(lst_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	ft_swap(lst_a);
	ft_swap(lst_b);
	write(1, "ss\n", 3);
}