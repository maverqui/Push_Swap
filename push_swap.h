/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:09:18 by maeverqu          #+#    #+#             */
/*   Updated: 2026/05/25 18:07:09 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct	s_stack	*next;
	struct	s_stack	*prev;
}	t_stack;

int	is_valid_arg(char *arg);

//UTILS
int	ft_atoi(char *str);

#endif