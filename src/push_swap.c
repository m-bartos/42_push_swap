/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 16:29:50 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_atoi(const char *str)
{
	int		i;
	long	sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - '0';
	number = number * sign;
	if (number <= INT_MAX && number >= INT_MIN)
		return (number);
	ft_putstr_fd("Error: at least one number is not integer", 1);
	exit(1);
}

t_node	*load_in_list(int argc, char **argv)
{
	char	**arr_of_ints;
	int		i;
	t_node	*stck;

	stck = NULL;
	if (argc == 2)
	{
		arr_of_ints = ft_split(argv[1], ' ');
		check_args(arr_length(arr_of_ints), arr_of_ints);
		i = 0;
		while (i < arr_length(arr_of_ints))
			ft_stckadd_back(&stck, ft_stcknew(ft_ps_atoi(arr_of_ints[i++])));
		free_array(arr_of_ints);
	}
	else
	{
		check_args(argc - 1, &(*(argv + 1)));
		i = 1;
		while (i < argc)
			ft_stckadd_back(&stck, ft_stcknew(ft_ps_atoi(argv[i++])));
	}
	return (stck);
}

int	main(int argc, char **argv)
{
	t_node	*stck_a;
	t_node	*stck_b;

	stck_a = NULL;
	stck_b = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Error: not enough parameters", 1);
		return (1);
	}
	stck_a = load_in_list(argc, argv);
	check_dup_nums(stck_a);
	if (is_list_sorted(stck_a) || ft_stcksize(stck_a) == 1)
	{
	}
	else if (ft_stcksize(stck_a) == 2)
		sort_two_nums(&stck_a);
	else if (ft_stcksize(stck_a) == 3)
		sort_three_nums(&stck_a);
	else
		turk_algo(&stck_a, &stck_b);
	ft_stckclear(&stck_a);
	ft_stckclear(&stck_b);
	return (0);
}
