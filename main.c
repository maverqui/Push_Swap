/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:55 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/23 12:36:31 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc < 2)
		return (EXIT_FAILURE);
	while (argv[i])
	{
		if(!is_valid_arg(argv[i]))
			clean_exit(argv);
		i++;
	}
	write(STDOUT_FILENO, "caca\n", 5);
	return (EXIT_SUCCESS);
}
