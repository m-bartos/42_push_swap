/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/07 19:53:50 by mbartos          ###   ########.fr       */
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
	while (stck != NULL)
	{
		ft_putnbr_fd(stck->number, 1);
		ft_putchar_fd('\n', 1);
		stck = stck->next;
	}
}

void	put_both_stck(t_node *stck_a, t_node *stck_b)
{
	ft_printf("A          B\n");
	while (1)
	{
		if (stck_a != NULL)
		{
			ft_putnbr_fd(stck_a->number, 1);
			if (stck_a->next != NULL)
				stck_a = stck_a->next;
		}
		ft_printf("       ");
		if (stck_b != NULL)
		{
			ft_putnbr_fd(stck_b->number, 1);
			if (stck_b->next != NULL)
				stck_b = stck_b->next;
		}
		ft_putchar_fd('\n', 1);
		if (stck_a == NULL && stck_b == NULL)
			break;
	}
	if (stck_a != NULL)
		ft_putnbr_fd(stck_a->number, 1);
	ft_printf("  ");
	if (stck_b != NULL)
		ft_putnbr_fd(stck_b->number, 1);
	ft_putchar_fd('\n', 1);
}

t_node	*sa_sb(t_node *stck)
{
	t_node	*first;
	t_node	*second;
	
	first = stck;
	second = stck->next;
	first->next = second->next;
	second->next = first;
	return (second);
}

void	pa(t_node **stck_a, t_node **stck_b)
{
	t_node	*second_b;
	
	if (stck_b == NULL)
		return ;
	second_b = (*stck_b)->next;
	(*stck_b)->next = *stck_a;
	*stck_a = *stck_b;
	*stck_b = second_b;
}

t_node	*ra_rb(t_node *stck)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = stck;
	second = stck->next;
	last = ft_stcklast(stck);
	last->next = first;
	first->next = NULL;
	return(second);
}

t_node	*rra_rrb(t_node *stck)
{
	t_node	*first;
	t_node	*second_last;
	t_node	*last;

	first = stck;
	second_last = ft_stck_seclast(stck);
	last = ft_stcklast(stck);
	second_last->next = NULL;
	last->next = first;
	return(last);
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
	lst_a = sa_sb(lst_a);
	ft_putchar_fd('\n', 1);
	put_stck(lst_a);
	lst_a = ra_rb(lst_a);
	ft_putchar_fd('\n', 1);
	put_stck(lst_a);
	lst_a = rra_rrb(lst_a);
	ft_putchar_fd('\n', 1);
	put_stck(lst_a);
	lst_b = ft_stcknew(1000);
	new = ft_stcknew(2000);
	ft_stckadd_back(&lst_b, new);
	pa(&lst_a, &lst_b);
	put_both_stck(lst_a, lst_b);
	ft_freestck(lst_a);
	return (0);
}
