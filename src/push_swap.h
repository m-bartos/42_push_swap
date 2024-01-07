/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:27:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/07 18:34:29 by mbartos          ###   ########.fr       */
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
t_node	*ft_stcknew(int number);
void	ft_stckadd_back(t_node **lst, t_node *new);
t_node	*ft_stcklast(t_node *lst);
t_node	*ft_stck_seclast(t_node *lst);
void	ft_freestck(t_node *lst);

#endif