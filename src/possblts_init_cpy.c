/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possblts_init_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:31:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 18:45:30 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	possblts_init(t_poss *possblts)
{
	possblts->operations = 0;
	possblts->ra = 0;
	possblts->rb = 0;
	possblts->rr = 0;
	possblts->rra = 0;
	possblts->rrb = 0;
	possblts->rrr = 0;
}

void	possblts_cpy(t_poss *dest, const t_poss *src)
{
	dest->num_a = src->num_a;
	dest->num_b = src->num_b;
	dest->operations = src->operations;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
}