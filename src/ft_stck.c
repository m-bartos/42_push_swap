/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:43:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 16:26:41 by mbartos          ###   ########.fr       */
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

// void	put_stck(t_node *stck)
// {
// 	ft_printf("-----\n");
// 	while (stck != NULL)
// 	{
// 		ft_putnbr_fd(stck->number, 1);
// 		ft_putchar_fd('\n', 1);
// 		stck = stck->next;
// 	}
// 	ft_printf("-----\n");
// }

// void	put_both_stck(t_node *stck_a, t_node *stck_b)
// {
// 	static int	fd;

// 	if (fd == 0)
// 	{
// 		fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 		fd = -1; // delete if you want to write stacks to output.txt
// 	}
// 	ft_putstr_fd("-----\n", fd);
// 	ft_putstr_fd("--A--\n", fd);
// 	while (stck_a != NULL)
// 	{
// 		ft_putnbr_fd(stck_a->number, fd);
// 		ft_putstr_fd("\n", fd);
// 		stck_a = stck_a->next;
// 	}
// 	ft_putstr_fd("--B--\n", fd);
// 	while (stck_b != NULL)
// 	{
// 		ft_putnbr_fd(stck_b->number, fd);
// 		ft_putstr_fd("\n", fd);
// 		stck_b = stck_b->next;
// 	}
// 	ft_putstr_fd("-----\n\n", fd);
// }
