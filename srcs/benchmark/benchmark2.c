/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <maeverqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:58:56 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/29 20:47:38 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	b_strategy(t_strat strat)
{
	//char	*adapt;
	//char	*simp;
	//char	*med;
	//char	*complex;

	//adapt = "--adaptive";
	//simp = "--simple";
	//med = "--medium";
	//complex = "--complex";

	//if (ft_strncmp(str, adapt, 10) == 0)
	//	write(2, "Adaptive / O(n√n)", 17);
	//else if (ft_strncmp(str, simp, 8) == 0)
	//	write(2, "Simple / O(n2)", 14);
	//else if (ft_strncmp(str, med, 8) == 0)
	//	write(2, "Medium / O(n√n)", 15);
	//else if (ft_strncmp(str, complex, 10) == 0)
	//	write(2, "Complex / O(n log n)", 20);
	//else
	//	return ;
	//write(2, "\n", 1);

	if (strat == STRAT_ADAPTIVE)
		write(2, "Adaptive / O(n√n)", 17);
	else if (strat == STRAT_SIMPLE)
		write(2, "Simple / O(n2)", 14);
	else if (strat == STRAT_MEDIUM)
		write(2, "Medium / O(n√n)", 15);
	else if (strat == STRAT_COMPLEX)
		write(2, "Complex / O(n log n)", 20);
	else
		return ;
	write(2, "\n", 1);
}

static int	count_total_ops(t_operations *ops)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb;
	total += ops->ra + ops->rb + ops->rr;
	total += ops->rra + ops->rrb + ops->rrr;
	return (total);
}

static void	print_bench_header(t_strat strat_flag, t_list **lst_a)
{
	write(2, "[bench] disorder: ", 18);
	ft_putfloat_fd(compute_disorder(lst_a), 2);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	b_strategy(strat_flag);
}

static void	print_ops_details(t_operations *operations)
{
	write(2, "\n[bench] sa: ", 13);
	ft_putnbr_fd(operations->sa, 2);
	write(2, "  sb: ", 5);
	ft_putnbr_fd(operations->sb, 2);
	write(2, "  ss: ", 5);
	ft_putnbr_fd(operations->ss, 2);
	write(2, "  pa: ", 5);
	ft_putnbr_fd(operations->pa, 2);
	write(2, "  pb: ", 5);
	ft_putnbr_fd(operations->pb, 2);
	write(2, "[bench]   ra: ", 13);
	ft_putnbr_fd(operations->ra, 2);
	write(2, "  rb: \t", 5);
	ft_putnbr_fd(operations->rb, 2);
	write(2, "  rr: \t", 5);
	ft_putnbr_fd(operations->rr, 2);
	write(2, "  rra:    ", 6);
	ft_putnbr_fd(operations->rra, 2);
	write(2, "  rrb:    ", 6);
	ft_putnbr_fd(operations->rrb, 2);
	write(2, "  rrr:    ", 6);
	ft_putnbr_fd(operations->rrr, 2);
	write(2, "\n", 1);
}

void	benchmark(t_operations *operations, t_strat strat_flag, t_list **lst_a)
{
	int	total;

	total = count_total_ops(operations);
	print_bench_header(strat_flag, lst_a);
	write(2, "\n[bench] total_ops:	", 20);
	ft_putnbr_fd(total, 2);
	print_ops_details(operations);
}
