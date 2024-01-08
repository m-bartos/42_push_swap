/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:59:44 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/08 15:06:25 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sa_sb(t_node *stck)
{
	t_node	*first;
	t_node	*second;
	
	first = stck;
	second = stck->next;
	first->next = second->next;
	second->next = first;
	return (second);
}

void	sa(t_node **stck_a)
{
	*stck_a = sa_sb(*stck_a);
	ft_printf("sa\n");
}

void	sb(t_node **stck_b)
{
	*stck_b = sa_sb(*stck_b);
	ft_printf("sb\n");
}

void	ss(t_node **stck_a, t_node **stck_b)
{
	*stck_a = sa_sb(*stck_a);
	*stck_b = sa_sb(*stck_b);
	ft_printf("ss\n");
}