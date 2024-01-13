/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/13 18:39:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	possblts_init(&lowest_possblts);
	lowest_possblts.operations = INT_MAX;
	while (stck_a_iter != NULL)
	{
		num = stck_a_iter->number;
		possblts.num_a = num;
		if (num < ft_stck_min(*stck_b))
			possblts.num_b = ft_stck_max(*stck_b);
		else if (num > ft_stck_max(*stck_b))
			possblts.num_b = ft_stck_max(*stck_b);
		else
			possblts.num_b = lower_num(*stck_b, num);
		get_numof_opers(&possblts, *stck_a, *stck_b);
		if (possblts.operations < lowest_possblts.operations)
			possblts_cpy(&lowest_possblts, &possblts);
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

	possblts_init(&possblts);
	while (*stck_b != NULL)
	{
		possblts_init(&possblts);
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

	possblts_init(&possblts);
	possblts.num_a = ft_stck_min(*stck_a);
	numof_r_rr_moves(*stck_a, possblts.num_a, &possblts.ra, &possblts.rra);
	if (possblts.ra <= possblts.rra)
		possblts.rra = 0;
	else
		possblts.ra = 0;
	do_operations(&possblts, stck_a, NULL);
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
