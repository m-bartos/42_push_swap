/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:15 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/09 10:14:15 by mbartos          ###   ########.fr       */
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

int	is_valid_number(char *str)
{
	while (*str)
	{
		if (ft_issign(*str))
			str++;
		else if (ft_isdigit(*str))
			return (1);
		else
			break ;
	}
	ft_putstr_fd("Error: wrong input.", 2);
	exit(1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_putstr_fd("Error: Not enough parameters", 2);
		exit(1);
	}
	else
	{
		i = 1;
		while (i < argc)
			is_valid_number(argv[i++]);
	}
}
