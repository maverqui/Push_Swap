/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:09:18 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 17:14:31 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct	s_list	*next;
}	t_list;

typedef struct s_operations
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
} t_operations;

//---OPERATIONS---
void	sa(t_list **lst_a, t_operations *operations);
void	sb(t_list **lst_b, t_operations *operations);
void	ss(t_list **lst_a, t_list **lst_b, t_operations *operations);
//-------------------------------------------------------
void	pa(t_list **lst_a, t_list **lst_b, t_operations *operations);
void	pb(t_list **lst_a, t_list **lst_b, t_operations *operations);
//-------------------------------------------------------
void	ra(t_list **lst_a, t_operations *operations);
void	rb(t_list **lst_b, t_operations *operations);
void	rr(t_list **lst_a, t_list **lst_b, t_operations *operations);
//-------------------------------------------------------
void	rra(t_list **lst_a, t_operations *operations);
void	rrb(t_list **lst_b, t_operations *operations);
void	rrr(t_list **lst_a, t_list **lst_b, t_operations *operations);

//---ALGO---
void	ft_bubble_sort(t_list **lst_a, t_operations *operations);
//---------------------------------------------------------
void	ft_chunk_sort(t_list **lst_a, t_operations *operations);

//---PARSING---
int		is_valid_arg(char *arg);
void	clean_exit(t_list **lst_a);
void	init_stack(t_list **lst_a, int argc, char **argv);

//---UTILS---
long	ft_atol(char *str);

//---UTILS2---
t_list	*ft_lstnew(int val);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list	*lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
//--------------------------------------------------------
float	compute_disorder(t_list **lst_a);


#endif