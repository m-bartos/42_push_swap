/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/09 11:27:03 by mbartos          ###   ########.fr       */
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
	ft_printf("-----\n");
	ft_printf("--A--\n");
	while (stck_a != NULL)
	{
		ft_putnbr_fd(stck_a->number, 1);
		ft_printf("\n");
		stck_a = stck_a->next;
	}
	ft_printf("--B--\n");
	while (stck_b != NULL)
	{
		ft_putnbr_fd(stck_b->number, 1);
		ft_printf("\n");
		stck_b = stck_b->next;
	}
	ft_printf("-----\n\n");
}

int	main(int argc, char **argv)
{
	t_node	*lst_a;
	t_node	*lst_b;
	t_node	*new;

	lst_a = NULL;
	lst_b = NULL;
	check_args(argc, argv);
	lst_a = load_in_list(argc, argv);
	put_stck(lst_a);
	three_nums(lst_a);
	// ft_putstr_fd("\n", 1);
	// rra(&lst_a);
	// put_stck(lst_a);
	// ft_putstr_fd("\n", 1);
	// rra(&lst_a);
	// put_stck(lst_a);
	// ft_putstr_fd("\n", 1);
	// rra(&lst_a);
	// put_stck(lst_a);
	// ft_putstr_fd("\n", 1);
	
	// lst_b = ft_stcknew(1000);
	// new = ft_stcknew(2000);
	// ft_stckadd_back(&lst_b, new);
	// pa(&lst_a, &lst_b);
	// put_both_stck(lst_a, lst_b);
	// pa(&lst_a, &lst_b);
	// put_both_stck(lst_a, lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// pb(&lst_a, &lst_b);
	// put_both_stck(lst_a, lst_b);
	// ft_freestck(lst_a);
	// ft_freestck(lst_b);
	return (0);
}
