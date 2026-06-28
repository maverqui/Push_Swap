/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorossel <jorossel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:55 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/28 20:37:58 by jorossel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_operations	operations;

	lst_a = NULL;
	lst_b = NULL;
	operations = (t_operations){0};
	if (argc < 2)
		return (EXIT_FAILURE);
	init_stack(&lst_a, argc, argv);
	force_algo(&lst_a, &lst_b, &operations, argv[1]);
	//ft_bubble_sort(&lst_a, &operations);
	//ft_chunk_sort(&lst_a, &operations);
	//ft_radix_sort(&lst_a, &lst_b, &operations);
	while(lst_a)
		lst_a = lst_a->next;
	write(STDOUT_FILENO, "caca\n", 5);
	return (EXIT_SUCCESS);
}
