/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:15 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 12:42:10 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add error for two or more of same values
// add error for value greater or smaller than MAX_INT MIN_INT

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	return (0);
}

void	is_valid_number(char *str)
{
	if (ft_issign(*str))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
		{
			ft_putstr_fd("Error: wrong input.", 2);
			exit(1);
		}
	}
}

void	check_args(int len, char **arr)
{
	int	i;

	i = 0;
	while (i < len)
		is_valid_number(arr[i++]);
}
