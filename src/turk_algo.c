/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/11 12:06:58 by mbartos          ###   ########.fr       */
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

	// start pushing from stack_a to stack_b according to turk_algo
	t_possible	new_possibilities;
	t_possible	*ptr_new_possibilities;
	t_possible	lowest_possibilities;
	int	number;
	t_node *stck_a_iter;
	ptr_new_possibilities = &new_possibilities;
	// --- WHILE LOOP STARTS---
	// CHECK if num of ints in stack_a != 3
	while (ft_stcksize(*stck_a) > 3)
	{
		stck_a_iter = *stck_a;
		lowest_possibilities.operations = 10000; // needs to be fixed and initialized properly!!!!
		// find what number from stack_a to push (lowest num of operations)
		while (stck_a_iter != NULL)
		{
			number = stck_a_iter->number;
			if (number < ft_stck_min(*stck_b))
			{
				// find num of operations - rr, rrr, ra, rrb, rra, rb
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, ft_stck_max(*stck_b));
				// check if num of operations from this number is lower then any previous
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
				//ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
			}
			// - finding if the number I want to push is bigger than the biggest number in stack_b
			else if (number > ft_stck_max(*stck_b))
			{
				// find num of operations - rr, rrr, ra, rrb, rra, rb
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, ft_stck_max(*stck_b));
				// check if num of operations from this number is lower then any previous
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
				//ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
			}
			else
			{
				// find num of operations - rr, rrr, ra, rrb, rra, rb
				get_numof_operations(&ptr_new_possibilities, *stck_a, *stck_b, number, closest_lower_num(*stck_b, number));
				// check if num of operations from this number is lower then any previous
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
				//ft_printf("NUMBER = %d, OPER = %d, ra = %d, rra = %d, rb = %d, rrb = %d\n", number, new_possibilities.operations, new_possibilities.ra, new_possibilities.rra, new_possibilities.rb, new_possibilities.rrb);
			}
			stck_a_iter = stck_a_iter->next;
		}
		//ft_printf("Lowest oper = %d\n", lowest_possibilities.operations);
		// apply the right amount of right operations and push the number in stack_b
		do_operations(&lowest_possibilities, stck_a, stck_b);
		pb(stck_a, stck_b);
		put_both_stck(*stck_a, *stck_b);
	}
	// --- WHILE LOOP ENDS ---
	
	// sort 3 ints in stack_a
	//ft_printf("Now sorting stack_a\n");
	three_nums(stck_a);
	put_both_stck(*stck_a, *stck_b);

	// start pushing back from stack_b to stack_a according to turk_algo
	//ft_printf("Start of pushing from stck_b back to stck_a: \n");
	// --- WHILE LOOP STARTS ---
	int	closest_higher;
	while (*stck_b != NULL)
	{
		// init of struct - create totally different struct? This is too big with useless variables - !! careful with do_operations function
		lowest_possibilities.operations = 0;
		lowest_possibilities.ra = 0;
		lowest_possibilities.rb = 0;
		lowest_possibilities.rr = 0;
		lowest_possibilities.rra = 0;
		lowest_possibilities.rrb = 0;
		lowest_possibilities.rrr = 0;
		// finding closest higher number in stack_a for first number in stck_b
		if ((*stck_b)->number > ft_stck_max(*stck_a))
			closest_higher = ft_stck_min(*stck_a);
		else
			closest_higher = closest_higher_num(*stck_a, (*stck_b)->number);
		//ft_printf("Closest higher: %d\n", closest_higher);
		// Calculate how many and which operation to use
		// Though - POSSIBLE IMPROVEMENT - also looking for RR and RRR - maybe they are more efficient?
		numof_r_rr_moves(*stck_a, closest_higher, &lowest_possibilities.ra, &lowest_possibilities.rra);
		// choose if ra or rra is more efficient
		if (lowest_possibilities.ra <= lowest_possibilities.rra)
			lowest_possibilities.rra = 0;
		else
			lowest_possibilities.ra = 0;
		// rotate the stack_a until desired number is on top
		do_operations(&lowest_possibilities, stck_a, stck_b);
		// push the number from stack_b to stack_a
		pa(stck_a, stck_b);
		put_both_stck(*stck_a, *stck_b);
	}
	// --- WHILE LOOP ENDS ---

	// rotate stack_a until lowest number on top
	//ft_printf("Rotate until the lowest number is on top: \n");
	numof_r_rr_moves(*stck_a, ft_stck_min(*stck_a), &lowest_possibilities.ra, &lowest_possibilities.rra);
	// choose if ra or rra is more efficient
	if (lowest_possibilities.ra <= lowest_possibilities.rra)
		lowest_possibilities.rra = 0;
	else
		lowest_possibilities.ra = 0;
	// do operations
	do_operations(&lowest_possibilities, stck_a, stck_b);
	put_both_stck(*stck_a, *stck_b);
	// DONE!
}
