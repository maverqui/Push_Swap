/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:50:16 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/11 11:29:55 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*current;

	if (!new_node || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_list	*ft_lstlast(t_list	*lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}