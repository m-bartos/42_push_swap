/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 16:53:11 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numof_r_rr_moves(t_node *stck, int num_to_move, int *rx, int *rrx)
{
	int	numof_rx;
	int	numof_rrx;
	int	before_num_to_find;

	before_num_to_find = 1;
	numof_rx = 0;
	numof_rrx = 0;
	while (stck != NULL)
	{
		if (stck->number == num_to_move)
			before_num_to_find = 0;
		else if (before_num_to_find == 1)
			numof_rx++;
		else
			numof_rrx++;
		stck = stck->next;
	}
	if (numof_rx > 0 || numof_rrx > 0)
		numof_rrx++;
	*rx = numof_rx;
	*rrx = numof_rrx;
}

int	rx_operations(t_poss *possibilities)
{
	if (possibilities->ra >= possibilities->rb)
		return (possibilities->ra);
	else
		return (possibilities->rb);
}

int	rrx_operations(t_poss *possibilities)
{
	if (possibilities->rra >= possibilities->rrb)
		return (possibilities->rra);
	else
		return (possibilities->rrb);
}

void	rr_rrr_optimaze(t_poss *possblts)
{
	int	rra_rb;
	int	ra_rrb;
	int	ra_rb;
	int	rra_rrb;

	ra_rb = rx_operations(possblts);
	ra_rrb = possblts->ra + possblts->rrb;
	rra_rb = possblts->rra + possblts->rb;
	rra_rrb = rrx_operations(possblts);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
	{
		if (possblts->ra >= possblts->rb)
		{
			possblts->operations = ra_rb;
			possblts->rr = possblts->rb;
			possblts->ra = possblts->ra - possblts->rb;
			possblts->rb = 0;
			possblts->rra = 0;
			possblts->rrb = 0;
		}
		else
		{
			possblts->operations = ra_rb;
			possblts->rr = possblts->ra;
			possblts->rb = possblts->rb - possblts->ra;
			possblts->ra = 0;
			possblts->rra = 0;
			possblts->rrb = 0;
		}
	}
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
	{
		if (possblts->rra >= possblts->rrb)
		{
			possblts->operations = rra_rrb;
			possblts->ra = 0;
			possblts->rb = 0;
			possblts->rrr = possblts->rrb;
			possblts->rra = possblts->rra - possblts->rrb;
			possblts->rrb = 0;
		}
		else
		{
			possblts->operations = rra_rrb;
			possblts->ra = 0;
			possblts->rb = 0;
			possblts->rrr = possblts->rra;
			possblts->rrb = possblts->rrb - possblts->rra;
			possblts->rra = 0;
		}
	}
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
	{
		possblts->operations = ra_rrb;
		possblts->rra = 0;
		possblts->rb = 0;
	}
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
	{
		possblts->operations = rra_rb;
		possblts->ra = 0;
		possblts->rrb = 0;
	}
}

// calculate n of ra and n of rra to get number on top of stack_a
// calculate n of rb and n of rrb to get max number on top of stack_b
void	get_numof_oper(t_poss	*possblts, t_node *stck_a, t_node *stck_b, int n_a, int n_b)
{
	init_possblts(possblts);
	numof_r_rr_moves(stck_a, n_a, &possblts->ra, &possblts->rra);
	numof_r_rr_moves(stck_b, n_b, &possblts->rb, &possblts->rrb);
	rr_rrr_optimaze(possblts);
}

int	lower_num(t_node *stck, int desired_num)
{
	int	closest_lower;

	closest_lower = INT_MIN;
	while (stck != NULL)
	{
		if (desired_num > stck->number && stck->number > closest_lower)
			closest_lower = stck->number;
		stck = stck->next;
	}
	return (closest_lower);
}

int	closest_higher_num(t_node *stck, int desired_num)
{
	int	closest_higher;

	closest_higher = INT_MAX;
	while (stck != NULL)
	{
		if (desired_num < stck->number && stck->number < closest_higher)
			closest_higher = stck->number;
		stck = stck->next;
	}
	return (closest_higher);
}

void	do_operations(t_poss *lowest_possblts, t_node **stck_a, t_node **stck_b)
{
	int	i;

	i = 0;
	while (i++ < lowest_possblts->ra)
		ra(stck_a);
	i = 0;
	while (i++ < lowest_possblts->rb)
		rb(stck_b);
	i = 0;
	while (i++ < lowest_possblts->rr)
		rr(stck_a, stck_b);
	i = 0;
	while (i++ < lowest_possblts->rra)
		rra(stck_a);
	i = 0;
	while (i++ < lowest_possblts->rrb)
		rrb(stck_b);
	i = 0;
	while (i++ < lowest_possblts->rrr)
		rrr(stck_a, stck_b);
}

int	is_list_sorted(t_node *lst)
{
	int	temp;

	temp = lst->number;
	while (lst != NULL)
	{
		if (temp > lst->number)
			return (0);
		temp = lst->number;
		lst = lst->next;
	}
	return (1);
}

// finding closest higher number in stack_a for first number in stck_b
// Calculate how many and which operation to use
// choose if ra or rra is more efficient
// rotate the stack_a until desired number is on top
// push the number from stack_b to stack_a
void	push_stck_b_back_to_a(t_node **stck_a, t_node **stck_b)
{
	int		closest_higher;
	t_poss	possblts;

	init_possblts(&possblts);
	while (*stck_b != NULL)
	{
		init_possblts(&possblts);
		if ((*stck_b)->number > ft_stck_max(*stck_a))
			closest_higher = ft_stck_min(*stck_a);
		else
			closest_higher = closest_higher_num(*stck_a, (*stck_b)->number);
		numof_r_rr_moves(*stck_a, closest_higher, &possblts.ra, &possblts.rra);
		if (possblts.ra <= possblts.rra)
			possblts.rra = 0;
		else
			possblts.ra = 0;
		do_operations(&possblts, stck_a, stck_b);
		pa(stck_a, stck_b);
	}
}

void	last_sort_of_stck_a(t_node **stck_a)
{
	t_poss	possblts;

	init_possblts(&possblts);
	numof_r_rr_moves(*stck_a, ft_stck_min(*stck_a), &possblts.ra, &possblts.rra);
	if (possblts.ra <= possblts.rra)
		possblts.rra = 0;
	else
		possblts.ra = 0;
	do_operations(&possblts, stck_a, NULL);
}

void	possible_cpy(t_poss *dest, const t_poss *src)
{
	dest->operations = src->operations;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
}

void	push_one_num_from_a_to_b(t_node **stck_a, t_node **stck_b)
{
	t_poss	possblts;
	t_poss	lowest_possblts;
	int		num;
	t_node	*stck_a_iter;

	stck_a_iter = *stck_a;
	init_possblts(&lowest_possblts);
	lowest_possblts.operations = INT_MAX;
	while (stck_a_iter != NULL)
	{
		num = stck_a_iter->number;
		if (num < ft_stck_min(*stck_b))
			get_numof_oper(&possblts, *stck_a, *stck_b, num, ft_stck_max(*stck_b));
		else if (num > ft_stck_max(*stck_b))
			get_numof_oper(&possblts, *stck_a, *stck_b, num, ft_stck_max(*stck_b));
		else
			get_numof_oper(&possblts, *stck_a, *stck_b, num, lower_num(*stck_b, num));
		if (possblts.operations < lowest_possblts.operations)
			possible_cpy(&lowest_possblts, &possblts);
		stck_a_iter = stck_a_iter->next;
	}
	do_operations(&lowest_possblts, stck_a, stck_b);
	pb(stck_a, stck_b);
}

// if number of ints is 4 -> push 1 to stack_b
// else (number of ints >= 5) -> push 2 to stack_b
// start pushing from stack_a to stack_b according to turk_algo
// --- WHILE LOOP STARTS---
// CHECK if num of ints in stack_a != 3
// find what number from stack_a to push (lowest num of operations)
// - finding if the number I want to push is bigger than the biggest number in stack_b
// check if num of operations from this number is lower then any previous
// apply the right amount of right operations and push the number in stack_b
// --- WHILE LOOP ENDS ---
void	pushing_nums_from_a_to_b(t_node **stck_a, t_node **stck_b)
{
	if (ft_stcksize(*stck_a) == 4)
		pb(stck_a, stck_b);
	else
	{
		pb(stck_a, stck_b);
		pb(stck_a, stck_b);
	}
	while (ft_stcksize(*stck_a) > 3)
		push_one_num_from_a_to_b(stck_a, stck_b);
}

void	turk_algo(t_node **stck_a, t_node **stck_b)
{
	pushing_nums_from_a_to_b(stck_a, stck_b);
	sort_three_nums(stck_a);
	push_stck_b_back_to_a(stck_a, stck_b);
	last_sort_of_stck_a(stck_a);
}
