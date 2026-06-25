/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:55 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/25 18:56:25 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_list	*lst_a;
	t_operations	operations;

	
	lst_a = NULL;
	operations = (t_operations){0};
	if (argc < 2)
		return (EXIT_FAILURE);
	init_stack(&lst_a, argc, argv);
	ft_bubble_sort(&lst_a, &operations);
	while(lst_a)
	{
		printf("%d\n" , lst_a->value);
		lst_a = lst_a->next;
	}
	write(STDOUT_FILENO, "caca\n", 5);
	return (EXIT_SUCCESS);
}
