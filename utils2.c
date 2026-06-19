/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:50:16 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/18 17:41:50 by maeverqu         ###   ########.fr       */
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

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}