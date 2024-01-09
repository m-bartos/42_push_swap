/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:58:02 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/09 10:14:51 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums(t_node *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->number;
	second = stack_a->next->number;
	third = stack_a->next->next->number;
	if (first < second && second < third)
		ft_printf("\n");
	else if (first > second && second < third && third > first)
		ft_printf("sa\n");
	else if (first > second && second < third && third < first)
		ft_printf("ra\n");
	else if (first < second && second > third && third > first)
		ft_printf("sa\nra\n");
	else if (first < second && second > third && third < first)
		ft_printf("rra\n");
	else if (first > second && second > third)
		ft_printf("sa\nrra\n");
}
