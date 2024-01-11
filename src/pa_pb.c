/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:01:15 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 17:06:29 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stck_a, t_node **stck_b)
{
	t_node	*second_b;

	if (*stck_b == NULL)
		return ;
	second_b = (*stck_b)->next;
	(*stck_b)->next = *stck_a;
	*stck_a = *stck_b;
	*stck_b = second_b;
	ft_printf("pa\n");
}

void	pb(t_node **stck_a, t_node **stck_b)
{
	t_node	*second_a;

	if (*stck_a == NULL)
		return ;
	second_a = (*stck_a)->next;
	(*stck_a)->next = *stck_b;
	*stck_b = *stck_a;
	*stck_a = second_a;
	ft_printf("pb\n");
}
