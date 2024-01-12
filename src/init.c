/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:31:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 12:10:03 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_possblts(t_poss *possblts)
{
	possblts->operations = 0;
	possblts->ra = 0;
	possblts->rb = 0;
	possblts->rr = 0;
	possblts->rra = 0;
	possblts->rrb = 0;
	possblts->rrr = 0;
}
