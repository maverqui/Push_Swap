/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:41:38 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 16:34:30 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rev_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*first;
	t_list	*current;

	if (!(*lst) || !lst || (*lst)->next == NULL)
		return ;
	temp = ft_lstlast(*lst);
	current = *lst;
	first = *lst;
	while (current->next->next)
		current = current->next;
	temp->next = first;
	*lst = temp;
	current->next = NULL;
}

void	rra(t_list **lst_a, t_operations *operations)
{
	ft_rev_rotate(lst_a);
	write(1, "rra\n", 4);
	operations->rra += 1;
}

void	rrb(t_list **lst_b, t_operations *operations)
{
	ft_rev_rotate(lst_b);
	write(1, "rrb\n", 4);
	operations->rrb += 1;
}

void	rrr(t_list **lst_a, t_list **lst_b, t_operations *operations)
{
	ft_rev_rotate(lst_a);
	ft_rev_rotate(lst_b);
	write(1, "rrr\n", 4);
	operations->rrr += 1;
}