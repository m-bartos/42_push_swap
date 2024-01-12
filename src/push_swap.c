/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/12 12:38:13 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_length(char	**arr)
{
	int	i;

	i = 0;
	while (*arr != NULL)
	{
		i++;
		arr++;
	}
	return (i);
}

t_node	*load_in_list(int argc, char **argv)
{
	char**	arr_of_ints;
	int		i;
	t_node	*stck;
	t_node	*new_node;
	

	stck = NULL;
	if (argc == 2)
	{
		arr_of_ints = ft_split(argv[1], ' ');
		check_args(arr_length(arr_of_ints), arr_of_ints);
		i = 0;
		while (i < arr_length(arr_of_ints))
		{
			new_node = ft_stcknew(ft_atoi(arr_of_ints[i]));
			ft_stckadd_back(&stck, new_node);
			i++;
		}
		free(arr_of_ints);
	}
	else
	{
		check_args(argc - 1, &(*(argv + 1)));
		i = 1;
		while (i < argc)
		{
			new_node = ft_stcknew(ft_atoi(argv[i]));
			ft_stckadd_back(&stck, new_node);
			i++;
		}
	}
	return (stck);
}

void	put_stck(t_node *stck)
{
	ft_printf("-----\n");
	while (stck != NULL)
	{
		ft_putnbr_fd(stck->number, 1);
		ft_putchar_fd('\n', 1);
		stck = stck->next;
	}
	ft_printf("-----\n");
}

void	put_both_stck(t_node *stck_a, t_node *stck_b)
{
	static int	fd;

	if (fd == 0)
	{
		fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd = -1; // delete if you want to write stacks to output.txt
	}
	ft_putstr_fd("-----\n", fd);
	ft_putstr_fd("--A--\n", fd);
	while (stck_a != NULL)
	{
		ft_putnbr_fd(stck_a->number, fd);
		ft_putstr_fd("\n", fd);
		stck_a = stck_a->next;
	}
	ft_putstr_fd("--B--\n", fd);
	while (stck_b != NULL)
	{
		ft_putnbr_fd(stck_b->number, fd);
		ft_putstr_fd("\n", fd);
		stck_b = stck_b->next;
	}
	ft_putstr_fd("-----\n\n", fd);
}

int	main(int argc, char **argv)
{
	t_node	*stck_a;
	t_node	*stck_b;
	t_node	*new;

	stck_a = NULL;
	stck_b = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Error: not enough parameters", 1);
		return (1);
	}
	stck_a = load_in_list(argc, argv);
	put_both_stck(stck_a, stck_b);
	if (is_list_sorted(stck_a) || ft_stcksize(stck_a) == 1)
		return (0);
	else if (ft_stcksize(stck_a) == 2)
		sort_two_nums(&stck_a);
	else if (ft_stcksize(stck_a) == 3)
		sort_three_nums(&stck_a);
	else
		turk_algo(&stck_a, &stck_b);
	return (0);
}
