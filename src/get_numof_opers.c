/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numof_opers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:23:56 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 18:39:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rx_operations(t_poss *possibilities)
{
	if (possibilities->ra >= possibilities->rb)
		return (possibilities->ra);
	else
		return (possibilities->rb);
}

int	rrx_operations(t_poss *possibilities)
{
	if (possibilities->rra >= possibilities->rrb)
		return (possibilities->rra);
	else
		return (possibilities->rrb);
}

void	numof_r_rr_moves(t_node *stck, int num_to_move, int *rx, int *rrx)
{
	int	numof_rx;
	int	numof_rrx;
	int	before_num_to_find;

	before_num_to_find = 1;
	numof_rx = 0;
	numof_rrx = 0;
	while (stck != NULL)
	{
		if (stck->number == num_to_move)
			before_num_to_find = 0;
		else if (before_num_to_find == 1)
			numof_rx++;
		else
			numof_rrx++;
		stck = stck->next;
	}
	if (numof_rx > 0 || numof_rrx > 0)
		numof_rrx++;
	*rx = numof_rx;
	*rrx = numof_rrx;
}

void	rr_rrr_optimaze(t_poss *possblts)
{
	int	rra_rb;
	int	ra_rrb;
	int	ra_rb;
	int	rra_rrb;

	ra_rb = rx_operations(possblts);
	ra_rrb = possblts->ra + possblts->rrb;
	rra_rb = possblts->rra + possblts->rb;
	rra_rrb = rrx_operations(possblts);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
		ra_rb_is_lowest(possblts, ra_rb);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		rra_rrb_is_lowest(possblts, rra_rrb);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
	{
		possblts->operations = ra_rrb;
		possblts->rra = 0;
		possblts->rb = 0;
	}
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
	{
		possblts->operations = rra_rb;
		possblts->ra = 0;
		possblts->rrb = 0;
	}
}

/**
 * @brief Calculates the number of operations needed for various movements.
 *
 * This function determines the number of operations required for both rotate 
 * (ra, rb) and * reverse rotate (rra, rrb) movements in the context of pushing
 * a number from stack_a to stack_b.
 *
 * @param possblts Pointer to the structure storing the number of operations
 * for each possibility.
 * @param stck_a Pointer to the top of stack_a (source stack).
 * @param stck_b Pointer to the top of stack_b (destination stack).
 * @param n_a Number to be pushed from stack_a to stack_b.
 * @param n_b Number in stack_b that affects the pushing strategy.
 */
void	get_numof_opers(t_poss	*possblts, t_node *stck_a, t_node *stck_b)
{
	possblts_init(possblts);
	numof_r_rr_moves(stck_a, possblts->num_a, &possblts->ra, &possblts->rra);
	numof_r_rr_moves(stck_b, possblts->num_b, &possblts->rb, &possblts->rrb);
	rr_rrr_optimaze(possblts);
}
