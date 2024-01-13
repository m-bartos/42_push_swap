/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 17:40:32 by mbartos          ###   ########.fr       */
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

/**
 * @brief Calculates the number of operations needed for various movements.
 *
 * This function determines the number of operations required for both rotate 
 * (ra, rb) and * reverse rotate (rra, rrb) movements in the context of pushing
 * a number from stack_a to stack_b.
 *
 * @param possblts Pointer to the structure storing the number of operations
 * for each possibility.
 * @param stck_a Pointer to the top of stack_a (source stack).
 * @param stck_b Pointer to the top of stack_b (destination stack).
 * @param n_a Number to be pushed from stack_a to stack_b.
 * @param n_b Number in stack_b that affects the pushing strategy.
 */
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

int	higher_num(t_node *stck, int desired_num)
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

/**
 * @brief Pushes numbers from stack_b back to stack_a in an optimal manner.
 *
 * This function efficiently pushes numbers from stack_b back to stack_a by
 *  considering the optimal * sequence of reverse and rotate operations 
 * (ra, rra) to reach the right position for insertion.
 *
 * @param stck_a Pointer to the top of stack_a (destination stack).
 * @param stck_b Pointer to the top of stack_b (source stack).
 */
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
			closest_higher = higher_num(*stck_a, (*stck_b)->number);
		numof_r_rr_moves(*stck_a, closest_higher, &possblts.ra, &possblts.rra);
		if (possblts.ra <= possblts.rra)
			possblts.rra = 0;
		else
			possblts.ra = 0;
		do_operations(&possblts, stck_a, stck_b);
		pa(stck_a, stck_b);
	}
}

/**
 * @brief Performs the last sorting step on stack_a.
 *
 * This function evaluates the optimal sequence of reverse and rotate operations
 *  (ra, rra) on stack_a * to achieve the final sorting state. It considers the 
 * number of moves needed for both operations * and executes the one with the 
 * minimum moves.
 *
 * @param stck_a Pointer to the top of stack_a (source stack).
 */
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

/**
 * @brief Pushes the number with the minimum operations needed from
 *  stack_a to stack_b.
 *
 * @details The algorithm works as follows:
 * 1. Initialize necessary variables and structures, including 'possblts'
 * to store the number of operations for each possibility and 'lowest_possblts'
 * to store the information about the lowest number of operations.
 *
 * 2. Iterate through each number in stack_a to evaluate the optimal candidate 
 * for pushing to stack_b.
 *
 * 3. For each number, calculate the number of operations needed for pushing it 
 * to stack_b by considering three scenarios:
 *    a. If the number is smaller than the minimum value in stack_b, calculate 
 * operations based on the maximum value in stack_b.
 *    b. If the number is greater than the maximum value in stack_b, calculate 
 * operations based on the maximum value in stack_b.
 *    c. Otherwise, calculate operations based on the value in stack_b that is 
 * lower than the current number.
 *
 * 4. Update 'lowest_possblts' with the information from 'possblts' if the 
 * current number requires fewer operations.
 *
 * 5. Perform the operations determined by 'lowest_possblts' to adjust both
 * stack_a and stack_b accordingly.
 *
 * 6. Finally, push the selected number from stack_a to stack_b using the 'pb' 
 * (push to stack_b) operation.
 *
 * This approach optimizes the pushing process by considering various scenarios
 * and choosing the number that minimizes the overall number of operations,
 * contributing to the efficiency of the sorting algorithm.
 *
 * @param stck_a Pointer to the top of stack_a (source stack).
 * @param stck_b Pointer to the top of stack_b (destination stack).
 */
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

/**
 * @brief Pushes numbers from stack_a to stack_b according to turk_algo until
 * there are only 3 numbers in stack_a.
 *
 * @param stck_a Pointer to the top of stack_a (source stack).
 * @param stck_b Pointer to the top of stack_b (destination stack).
 */
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

/**
 * @brief Implements the "turk_algorithm" function, a sorting algorithm
 * with specific steps.
 *
 * Algorithm Steps:
 * 1. Start pushing integers from stack_a to stack_b according to turk_algo.
 * 2. When there are only 3 numbers in stack_a, sort stack_a.
 * 3. Push numbers from stack_b back to stack_a.
 * 4. Sort stack_a.
 *
 * @param stck_a Pointer to the top of stack_a (source stack).
 * @param stck_b Pointer to the top of stack_b (destination stack).
 */
void	turk_algo(t_node **stck_a, t_node **stck_b)
{
	pushing_nums_from_a_to_b(stck_a, stck_b);
	sort_three_nums(stck_a);
	push_stck_b_back_to_a(stck_a, stck_b);
	last_sort_of_stck_a(stck_a);
}
