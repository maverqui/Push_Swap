/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:19:26 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/11 16:36:50 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!(*lst) || !lst || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	temp = *lst;
	*lst = (*lst)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_list	**lst_a)
{
	ft_rotate(lst_a);
	write(1, "ra\n", 3);
}

void	rb(t_list	**lst_b)
{
	ft_rotate(lst_b);
	write(1, "rb\n", 3);
}