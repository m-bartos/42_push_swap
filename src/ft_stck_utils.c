/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stck_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:21:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 16:23:41 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stcksize(t_node *lst)
{
	size_t	length;

	if (lst == NULL)
		return (0);
	length = 0;
	while (lst != NULL)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}

int	ft_stck_min(t_node *lst)
{
	int	min;

	min = lst->number;
	while (lst != NULL)
	{
		if (min > lst->number)
			min = lst->number;
		lst = lst->next;
	}
	return (min);
}

int	ft_stck_max(t_node *lst)
{
	int	max;

	max = lst->number;
	while (lst != NULL)
	{
		if (max < lst->number)
			max = lst->number;
		lst = lst->next;
	}
	return (max);
}

t_node	*ft_stcklast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_node	*ft_stck_seclast(t_node *lst)
{
	t_node	*sec_lst;

	if (lst == NULL)
		return (NULL);
	sec_lst = lst;
	while (lst->next != NULL)
	{
		sec_lst = lst;
		lst = lst->next;
	}
	return (sec_lst);
}
