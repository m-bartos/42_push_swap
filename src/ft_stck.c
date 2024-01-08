/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:43:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/07 18:34:21 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stcknew(int number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->index = 0;
	new_node->prev = NULL;
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
