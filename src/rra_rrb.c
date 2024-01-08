/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:02:55 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/08 15:07:58 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*rra_rrb(t_node *stck)
{
	t_node	*first;
	t_node	*second_last;
	t_node	*last;

	first = stck;
	second_last = ft_stck_seclast(stck);
	last = ft_stcklast(stck);
	second_last->next = NULL;
	last->next = first;
	return(last);
}

void	rra(t_node **stck_a)
{
	*stck_a = rra_rrb(*stck_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stck_b)
{
	*stck_b = rra_rrb(*stck_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stck_a, t_node **stck_b)
{
	*stck_a = rra_rrb(*stck_a);
	*stck_b = rra_rrb(*stck_b);
	ft_printf("rrr\n");
}
