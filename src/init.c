/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:31:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 16:32:20 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_possibilities(t_possible *possibilities)
{
	possibilities->operations = 0;
	possibilities->ra = 0;
	possibilities->rb = 0;
	possibilities->rr = 0;
	possibilities->rra = 0;
	possibilities->rrb = 0;
	possibilities->rrr = 0;
}
