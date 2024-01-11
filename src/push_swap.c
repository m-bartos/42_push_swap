/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 16:17:26 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*load_in_list(int argc, char **argv)
{
	int		i;
	t_node	*stck;
	t_node	*new_node;

	stck = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = ft_stcknew(ft_atoi(argv[i]));
		ft_stckadd_back(&stck, new_node);
		i++;
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
	check_args(argc, argv);
	stck_a = load_in_list(argc, argv);
	put_both_stck(stck_a, stck_b);
	if (is_list_sorted(stck_a) || ft_stcksize(stck_a) == 1)
		return (0);
	else if (ft_stcksize(stck_a) == 2)
		two_nums(&stck_a);
	else if (ft_stcksize(stck_a) == 3)
		three_nums(&stck_a);
	else
		turk_algo(&stck_a, &stck_b);
	return (0);
}