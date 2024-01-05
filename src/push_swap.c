/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:12:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/05 16:31:14 by mbartos          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_node	*lst_a;

	check_args(argc, argv);
	lst_a = load_in_list(argc, argv);
	put_stck(lst_a);
	ft_freestck(lst_a);
	return (0);
}
