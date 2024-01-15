/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:15 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/15 16:03:37 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_wrong_input(char **arr_of_ints)
{
	if (arr_of_ints != NULL)
		free_array(arr_of_ints);
	ft_putstr_fd("Error: wrong input\n", 2);
	exit(1);
}

void	put_wrong_type(char **arr_of_ints, t_node **stck)
{
	if (arr_of_ints != NULL)
		free_array(arr_of_ints);
	ft_stckclear(stck);
	ft_putstr_fd("Error: at least one number is not integer\n", 2);
	exit(1);
}

void	check_dup_nums(t_node *stck)
{
	t_node	*stck_runner;
	t_node	*stck_first;

	stck_first = stck;
	while (stck != NULL)
	{
		stck_runner = stck->next;
		while (stck_runner != NULL)
		{
			if (stck->number == stck_runner->number)
			{
				ft_putstr_fd("Error: Duplicate numbers\n", 2);
				ft_stckclear(&stck_first);
				exit(1);
			}
			stck_runner = stck_runner->next;
		}
		stck = stck->next;
	}
}

int	is_valid_number(char *str)
{
	if (ft_issign(*str))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int len, char **arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (is_valid_number(arr[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}
