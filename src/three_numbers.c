/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:58:02 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 16:39:47 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nums(t_node **stck_a)
{
	if (is_list_sorted(*stck_a))
		return ;
	else
		ra(stck_a);
}

void	sort_three_nums(t_node **stck_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stck_a)->number;
	second = (*stck_a)->next->number;
	third = (*stck_a)->next->next->number;
	if (first > second && second < third && third > first)
		sa(stck_a);
	else if (first > second && second < third && third < first)
		ra(stck_a);
	else if (first < second && second > third && third > first)
	{
		sa(stck_a);
		ra(stck_a);
	}
	else if (first < second && second > third && third < first)
		rra(stck_a);
	else if (first > second && second > third)
	{
		sa(stck_a);
		rra(stck_a);
	}
}
