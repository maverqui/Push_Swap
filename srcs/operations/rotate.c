/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:19:26 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 18:25:46 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_rotate(t_list **lst)
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

void	ra(t_list **lst_a, t_operations *operations)
{
	ft_rotate(lst_a);
	write(1, "ra\n", 3);
	operations->ra += 1;
}

void	rb(t_list **lst_b, t_operations *operations)
{
	ft_rotate(lst_b);
	write(1, "rb\n", 3);
	operations->rb += 1;
}

void	rr(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	write(1, "rr\n", 3);
	operations->rr += 1;
}