/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:14:49 by maeverqu          #+#    #+#             */
/*   Updated: 2026/05/25 17:52:53 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1 || 0
static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!(is_digit(arg[i])))
			return (0);
		i++;
	}
	return (1);
}