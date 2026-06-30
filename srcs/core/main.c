/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:55 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:14 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_option(t_data *data, char *arg)
{
	if (ft_strcmp(arg, "bench") == 0)
		data->operations.bench =  1;
	else if (ft_strcmp(arg, "simple") == 0)
		data->strat = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "medium") == 0)
		data->strat = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "complex") == 0)
		data->strat = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "adaptive") == 0)
		data->strat = STRAT_ADAPTIVE;
	else
		clean_exit(&data->lst_a);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc < 2)
		return (EXIT_FAILURE);
	data = (t_data){0};
	argv++;
	while (argv && ft_strncmp(argv[0], "--", 2) == 0)
	{
		check_option(&data, &argv[0][2]);
		argv++;
	}
	init_stack(&data.lst_a, argv);
	data.disorder = compute_disorder(&data.lst_a);
	strat_sort(&data);
	ft_lstclear(&data.lst_a);
	ft_lstclear(&data.lst_b);
	if (data.operations.bench == 1)
		benchmark(&data);
	return (EXIT_SUCCESS);
}
