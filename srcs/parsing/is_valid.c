/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:14:49 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/29 20:38:13 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void clean_exit(t_list **lst_a)
{
	ft_lstclear(lst_a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	isnt_double(int num, t_list *stack)
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

void	init_stack(t_list **lst_a, int argc, char **argv)
{
    int   i;
    long  value;
    t_list *new_node;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_arg(argv[i]))
            clean_exit(lst_a);
        value = ft_atol(argv[i]);
		if (value > 2147483647 || value < -2147483648)
			clean_exit(lst_a);
        if (!isnt_double((int)value, *lst_a))
			clean_exit(lst_a);
        new_node = ft_lstnew((int)value);
        if (!new_node)
            clean_exit(lst_a);
        ft_lstadd_back(lst_a, new_node);
        i++;
    }
}