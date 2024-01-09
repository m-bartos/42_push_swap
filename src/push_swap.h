/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:27:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/09 11:32:02 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct node
{
	int			number;
	int			index;
	struct node	*prev;
	struct node	*next;
}		t_node;

// errors.c
void	check_args(int argc, char **argv);

// ft_stck.c
int		ft_stcksize(t_node *lst);
t_node	*ft_stcknew(int number);
void	ft_stckadd_back(t_node **lst, t_node *new);
t_node	*ft_stcklast(t_node *lst);
t_node	*ft_stck_seclast(t_node *lst);
void	ft_freestck(t_node *lst);

// pa_pb.c
void	pa(t_node **stck_a, t_node **stck_b);
void	pb(t_node **stck_a, t_node **stck_b);

// ra_rb.c
void	ra(t_node **stck_a);
void	rb(t_node **stck_b);
void	rr(t_node **stck_a, t_node **stck_b);

// rra_rrb.c
void	rra(t_node **stck_a);
void	rrb(t_node **stck_b);
void	rrr(t_node **stck_a, t_node **stck_b);

// sa_sb.c
void	sa(t_node **stck_a);
void	sb(t_node **stck_b);
void	ss(t_node **stck_a, t_node **stck_b);

// three_numbers.c
void	three_nums(t_node *stack_a);

#endif