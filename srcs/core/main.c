/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorossel <jorossel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:55 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/29 21:40:44 by jorossel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_operations	operations;
	t_strat strat_flag;

	

	if (argc < 2)
		return (EXIT_FAILURE);
	lst_a = NULL;
	lst_b = NULL;
	strat_flag =STRAT_NONE;
	operations = (t_operations){0};
	operations.bench = 0;
	init_stack(&lst_a, argc, argv);
	adaptive_algo(&lst_a, &lst_b, &operations);
	//check_flags(lst_a, lst_b, operations, argv);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	if (operations.bench == 1)
		benchmark(&operations, strat_flag, &lst_a);
	return (EXIT_SUCCESS);
}
