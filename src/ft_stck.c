/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:43:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 15:43:17 by mbartos          ###   ########.fr       */
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

t_node	*ft_stcknew(int number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	ft_stckadd_back(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_stcklast(*lst);
		last_node->next = new;
	}
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

void	ft_freestck(t_node *lst)
{
	t_node	*temp_node;

	while (lst != NULL)
	{
		temp_node = lst;
		lst = lst->next;
		free(temp_node);
	}
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

void	ft_stckclear(t_node **lst)
{
	t_node	*temp;
	t_node	*actual_node;

	if (lst == NULL || *lst == NULL)
		return ;
	actual_node = *lst;
	while (actual_node != NULL)
	{
		temp = actual_node->next;
		free(actual_node);
		actual_node = temp;
	}
	*lst = NULL;
}