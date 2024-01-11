/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:02:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 17:04:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ra_rb(t_node *stck)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = stck;
	second = stck->next;
	last = ft_stcklast(stck);
	last->next = first;
	first->next = NULL;
	return (second);
}

void	ra(t_node **stck_a)
{
	*stck_a = ra_rb(*stck_a);
	ft_printf("ra\n");
}

void	rb(t_node **stck_b)
{
	*stck_b = ra_rb(*stck_b);
	ft_printf("rb\n");
}

void	rr(t_node **stck_a, t_node **stck_b)
{
	*stck_a = ra_rb(*stck_a);
	*stck_b = ra_rb(*stck_b);
	ft_printf("rr\n");
}
