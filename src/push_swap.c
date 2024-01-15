/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/15 16:18:15 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str, char **arr, t_node **stck)
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
	put_wrong_type(arr, stck);
	exit (1);
}

t_node	*load_in_list(int argc, char **argv)
{
	char	**arr;
	int		i;
	t_node	*stck;

	arr = NULL;
	stck = NULL;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (check_args(arr_length(arr), arr) == 0)
			put_wrong_input(arr);
		i = 0;
		while (i < arr_length(arr))
			ft_stckadd_back(&stck, ft_stcknew(ps_atoi(arr[i++], arr, &stck)));
		free_array(arr);
	}
	else
	{
		if (check_args(argc - 1, &(*(argv + 1))) == 0)
			put_wrong_input(NULL);
		i = 1;
		while (i < argc)
			ft_stckadd_back(&stck, ft_stcknew(ps_atoi(argv[i++], NULL, &stck)));
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
		return (0);
	stck_a = load_in_list(argc, argv);
	check_dup_nums(stck_a);
	if (is_stck_sorted(stck_a) || ft_stcksize(stck_a) == 1)
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
