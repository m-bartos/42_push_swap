/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numof_opers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:30:49 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 18:37:12 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lower_num(t_node *stck, int desired_num)
{
	int	closest_lower;

	closest_lower = INT_MIN;
	while (stck != NULL)
	{
		if (desired_num > stck->number && stck->number > closest_lower)
			closest_lower = stck->number;
		stck = stck->next;
	}
	return (closest_lower);
}

int	higher_num(t_node *stck, int desired_num)
{
	int	closest_higher;

	closest_higher = INT_MAX;
	while (stck != NULL)
	{
		if (desired_num < stck->number && stck->number < closest_higher)
			closest_higher = stck->number;
		stck = stck->next;
	}
	return (closest_higher);
}

void	ra_rb_is_lowest(t_poss *possblts, int ra_rb_oper)
{
	if (possblts->ra >= possblts->rb)
	{
		possblts->operations = ra_rb_oper;
		possblts->rr = possblts->rb;
		possblts->ra = possblts->ra - possblts->rb;
		possblts->rb = 0;
		possblts->rra = 0;
		possblts->rrb = 0;
	}
	else
	{
		possblts->operations = ra_rb_oper;
		possblts->rr = possblts->ra;
		possblts->rb = possblts->rb - possblts->ra;
		possblts->ra = 0;
		possblts->rra = 0;
		possblts->rrb = 0;
	}
}

void	rra_rrb_is_lowest(t_poss *possblts, int rra_rrb_oper)
{
	if (possblts->rra >= possblts->rrb)
	{
		possblts->operations = rra_rrb_oper;
		possblts->ra = 0;
		possblts->rb = 0;
		possblts->rrr = possblts->rrb;
		possblts->rra = possblts->rra - possblts->rrb;
		possblts->rrb = 0;
	}
	else
	{
		possblts->operations = rra_rrb_oper;
		possblts->ra = 0;
		possblts->rb = 0;
		possblts->rrr = possblts->rra;
		possblts->rrb = possblts->rrb - possblts->rra;
		possblts->rra = 0;
	}
}
