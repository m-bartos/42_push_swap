/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/10 15:23:16 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numof_r_rr_moves (t_node *stck, int num_to_move, int *r, int *rr)
{
	int	numof_r;
	int	numof_rr;
	int	before_num_to_find;

	before_num_to_find = 1;
	numof_r = 0;
	numof_rr = 0;
	while (stck != NULL)
	{
		if (stck->number == num_to_move)
			before_num_to_find = 0;
		else if (before_num_to_find == 1)
			numof_r++;
		else
			numof_rr++;
		stck = stck->next;
	}
	if (numof_r > 0 || numof_rr > 0)
		numof_rr++;
	*r = numof_r;
	*rr = numof_rr;
	// ft_printf("r = %d, rr = %d\n", *r, *rr);
}

void	rr_rrr_optimaze(t_possible **possibilities)
{
	int	rra_rb;
	int	ra_rrb;
	int	ra_rb;
	int	rra_rrb;

	ra_rb = (*possibilities)->ra + (*possibilities)->rb; // possible improvement for rr
	ra_rrb = (*possibilities)->ra + (*possibilities)->rrb;
	rra_rb = (*possibilities)->rra + (*possibilities)->rb;
	rra_rrb = (*possibilities)->rra + (*possibilities)->rrb; // possible improvement for rrr
	// ft_printf("ra_rb = %d, ra_rrb = %d, rra_rb = %d, rra_rrb = %d\n", ra_rb, ra_rrb, rra_rb, rra_rrb);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
	{
		(*possibilities)->operations = ra_rb;
		(*possibilities)->rra = 0;
		(*possibilities)->rrb = 0;
	}
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
	{
		(*possibilities)->operations = rra_rrb;
		(*possibilities)->ra = 0;
		(*possibilities)->rb = 0;
	}
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
	{
		(*possibilities)->operations = ra_rrb;
		(*possibilities)->rra = 0;
		(*possibilities)->rb = 0;
	}
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
	{
		(*possibilities)->operations = rra_rb;
		(*possibilities)->ra = 0;
		(*possibilities)->rrb = 0;
	}
	// ft_printf("ra_rb = %d, ra_rrb = %d, rra_rb = %d, rra_rrb = %d\n", ra_rb, ra_rrb, rra_rb, rra_rrb);
}

void	get_numof_operations(t_possible	**possibilities, t_node *stck_a, t_node *stck_b, int num_a, int num_b)
{
	// calculate n of ra and n of rra to get number on top of stack_a
	numof_r_rr_moves(stck_a, num_a, &(*possibilities)->ra, &(*possibilities)->rra);
	// calculate n of rb and n of rrb to get max number on top of stack_b
	numof_r_rr_moves(stck_b, num_b, &(*possibilities)->rb, &(*possibilities)->rrb);
	rr_rrr_optimaze(possibilities);
}

int	closest_lower_num(t_node *stck, int desired_num)
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

/*
typedef struct possible
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		operations;
}			t_possible;
*/

void	do_operations(t_possible *lowest_possibilities, t_node **stck_a, t_node **stck_b)
{
	int	i;

	i = 0;
	while (i++ < lowest_possibilities->ra)
		ra(stck_a);
	i = 0;
	while (i++ < lowest_possibilities->rb)
		rb(stck_b);
	// i = 0;
	// while (i++ < lowest_possibilities->rr)
	// 	rr(stck_a, stck_b);
	i = 0;
	while (i++ < lowest_possibilities->rra)
		rra(stck_a);
	i = 0;
	while (i++ < lowest_possibilities->rrb)
		rrb(stck_b);
	// i = 0;
	// while (i++ < lowest_possibilities->rrr)
	// 	rrr(stck_a, stck_b);
}

void	turk_algo(t_node **stck_a, t_node **stck_b)
{
	// if number of ints is 4 -> push 1 to stack_b
	// else (number of ints >= 5) -> push 2 to stack_b
	if (ft_stcksize(*stck_a) == 4)
		pb(stck_a, stck_b);
	else
	{
		pb(stck_a, stck_b);
		pb(stck_a, stck_b);
	}
	put_both_stck(*stck_a, *stck_b);
	// --- WHILE LOOP STARTS---
	// CHECK if num of ints in stack_a != 3
	t_possible	new_possibilities;
	t_possible	*ptr_new_possibilities;
	t_possible	lowest_possibilities;
	int	number;
	t_node *stck_a_iter;

	ptr_new_possibilities = &new_possibilities;
	while (ft_stcksize(*stck_a) > 3)
	{
		stck_a_iter = *stck_a;
		lowest_possibilities.operations = 10000; // needs to be fixed and initialized properly!!!!
		// find what number from stack_a to push (lowest num of operations)
		// - finding if the number I want to push is smaller than the smallest number in stack_b
		while (stck_a_iter != NULL)
		{
			number = stck_a_iter->number;
			if (number < ft_stck_min(*stck_b))
			{
				// need to rotate stack_B to have max int in stack_B on top and then push
				// calculate n of ra and n of rra to get number on top of stack_a
				// calculate n of rb and n of rrb to get max number on top of stack_b
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, ft_stck_max(*stck_b));
				if (new_possibilities.operations < lowest_possibilities.operations)
				{
					lowest_possibilities.operations = new_possibilities.operations;
					lowest_possibilities.ra = new_possibilities.ra;
					lowest_possibilities.rb = new_possibilities.rb;
					lowest_possibilities.rr = new_possibilities.rr;
					lowest_possibilities.rra = new_possibilities.rra;
					lowest_possibilities.rrb = new_possibilities.rrb;
					lowest_possibilities.rrr = new_possibilities.rrr;
				}
				ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
				// find to lowest number of operations - rr, rrr, ra, rrb, rra, rb
			}
			// - finding if the number I want to push is bigger than the biggest number in stack_b
			else if (number > ft_stck_max(*stck_b))
			{
				// numof_r_rr_moves(*stck_a, number, &(possibilities.ra), &(possibilities.rra));
				// numof_r_rr_moves(*stck_b, ft_stck_max(*stck_b), &(possibilities.rb), &(possibilities.rrb));
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, ft_stck_max(*stck_b));
				if (new_possibilities.operations < lowest_possibilities.operations)
				{
					lowest_possibilities.operations = new_possibilities.operations;
					lowest_possibilities.ra = new_possibilities.ra;
					lowest_possibilities.rb = new_possibilities.rb;
					lowest_possibilities.rr = new_possibilities.rr;
					lowest_possibilities.rra = new_possibilities.rra;
					lowest_possibilities.rrb = new_possibilities.rrb;
					lowest_possibilities.rrr = new_possibilities.rrr;
				}
				ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
			}
			else
			{
				// number is in between values in stack_b
				int	closest_lower;
				// - finding closest lower number in stack_b
				closest_lower = closest_lower_num(*stck_b, number);
				// calculate n of ra and n of rra to get number on top of stack_a
				//numof_r_rr_moves(*stck_a, number, &(possibilities.ra), &(possibilities.rra));
				// calculate n of rb and n of rrb to get max number on top of stack_b
				//numof_r_rr_moves(*stck_b, closest_lower, &(possibilities.rb), &(possibilities.rrb));
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, closest_lower);
				if (new_possibilities.operations < lowest_possibilities.operations)
				{
					lowest_possibilities.operations = new_possibilities.operations;
					lowest_possibilities.ra = new_possibilities.ra;
					lowest_possibilities.rb = new_possibilities.rb;
					lowest_possibilities.rr = new_possibilities.rr;
					lowest_possibilities.rra = new_possibilities.rra;
					lowest_possibilities.rrb = new_possibilities.rrb;
					lowest_possibilities.rrr = new_possibilities.rrr;
				}
				ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
				// -- could be calculated as ra and rb and then count how many times ra and rb are both there
			}
			stck_a_iter = stck_a_iter->next;
		}
		ft_printf("Lowest oper = %d\n", lowest_possibilities.operations);
		do_operations(&lowest_possibilities, stck_a, stck_b);
		pb(stck_a, stck_b);
		put_both_stck(*stck_a, *stck_b);
		// choose the number with the lowest operations
		// apply the right amount of right operations and push the number in stack_b
	}
	ft_printf("Now sorting stack_a\n");
	three_nums(stck_a);
	put_both_stck(*stck_a, *stck_b);
	// --- WHILE LOOP ENDS ---

	// --- WHILE LOOP STARTS ---
	// start pushing back from stack_b to stack_a according to algo
	// - finding closest higher number in stack_b and rotate the stack_a until this number is on top
	// - push number from stack_b to stack_a
	// --- WHILE LOOP ENDS ---

	// rotate stack_a until lowest number at the top
	// DONE!
}
