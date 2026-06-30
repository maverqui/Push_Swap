/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeverqu <mae.verquin@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:58:56 by maeverqu          #+#    #+#             */
/*   Updated: 2026/06/30 17:25:18 by maeverqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	b_strategy(t_strat strat)
{
	if (strat == STRAT_ADAPTIVE)
		write(2, "Adaptive / O(n√n)", 20);
	else if (strat == STRAT_SIMPLE)
		write(2, "Simple / O(n2)", 15);
	else if (strat == STRAT_MEDIUM)
		write(2, "Medium / O(n√n)", 18);
	else if (strat == STRAT_COMPLEX)
		write(2, "Complex / O(n log n)", 21);
	else
		return ;
}

static int	count_total_ops(t_operations *ops)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb;
	total += ops->ra + ops->rb + ops->rr;
	total += ops->rra + ops->rrb + ops->rrr;
	return (total);
}

static void	print_bench_header(t_data *data)
{
	write(2, "[bench] disorder:\t", 19);
	ft_putfloat_fd(data->disorder * 100, 2);
	write(2, "%\n", 2);
	write(2, "[bench] strategy:\t", 19);
	if (data->disorder != 0.0)
		b_strategy(data->strat);
	else
		write(2, "(null)", 6);
}

static void	print_ops_details(t_operations *operations)
{
	write(2, "\n[bench]\tsa:\t", 14);
	ft_putnbr_fd(operations->sa, 2);
	write(2, "\tsb:\t", 6);
	ft_putnbr_fd(operations->sb, 2);
	write(2, "\tss:\t", 6);
	ft_putnbr_fd(operations->ss, 2);
	write(2, "\tpa:\t", 6);
	ft_putnbr_fd(operations->pa, 2);
	write(2, "\tpb:\t", 6);
	ft_putnbr_fd(operations->pb, 2);
	write(2, "\n[bench]\tra:\t", 14);
	ft_putnbr_fd(operations->ra, 2);
	write(2, "\trb:\t", 6);
	ft_putnbr_fd(operations->rb, 2);
	write(2, "\trr:\t", 6);
	ft_putnbr_fd(operations->rr, 2);
	write(2, "\trra:\t", 7);
	ft_putnbr_fd(operations->rra, 2);
	write(2, "\trrb:\t", 7);
	ft_putnbr_fd(operations->rrb, 2);
	write(2, "\trrr:\t", 7);
	ft_putnbr_fd(operations->rrr, 2);
	write(2, "\n", 1);
}

void	benchmark(t_data *data)
{
	int	total;

	total = count_total_ops(&data->operations);
	print_bench_header(data);
	write(2, "\n[bench] total_ops:	", 20);
	ft_putnbr_fd(total, 2);
	print_ops_details(&data->operations);
}
