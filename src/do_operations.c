/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:28:48 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 18:32:43 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_operations(t_poss *lowest_possblts, t_node **stck_a, t_node **stck_b)
{
	int	i;

	i = 0;
	while (i++ < lowest_possblts->ra)
		ra(stck_a);
	i = 0;
	while (i++ < lowest_possblts->rb)
		rb(stck_b);
	i = 0;
	while (i++ < lowest_possblts->rr)
		rr(stck_a, stck_b);
	i = 0;
	while (i++ < lowest_possblts->rra)
		rra(stck_a);
	i = 0;
	while (i++ < lowest_possblts->rrb)
		rrb(stck_b);
	i = 0;
	while (i++ < lowest_possblts->rrr)
		rrr(stck_a, stck_b);
}
