/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:14:49 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/06 18:16:13 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void clean_exit()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

//1 || 0
static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	isnt_double(int num, t_list *stack)
{
	while (stack)
	{
		if (stack->value == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!(is_digit(arg[i])))
			return (0);
		i++;
	}
	return (1);
}

//int	check_and_add()