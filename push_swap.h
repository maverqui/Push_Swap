/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:09:18 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/12 15:26:45 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct	s_list	*next;
	struct	s_list	*prev;
}	t_list;

//---OPERATIONS---
void	sa(t_list **lst_a);
void	sb(t_list **lst_b);
void	ss(t_list **lst_a, t_list **lst_b);
//-------------------------------------------------------
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
//-------------------------------------------------------
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
//-------------------------------------------------------
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);

//---PARSING---
int		is_valid_arg(char *arg);
void	clean_exit();

//---UTILS---
int		ft_atoi(char *str);

//---UTILS2---
t_list	*ft_lstnew(int val);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list	*lst);
int		ft_lstsize(t_list *lst);

#endif