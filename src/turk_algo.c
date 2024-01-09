/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:50 by mbartos           #+#    #+#             */
/*   Updated: 2024/01/09 13:09:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	// --- WHILE LOOP STARTS---
	// CHECK if num of ints in stack_a != 3

	// find what number from stack_a to push (lowest num of operations)
	// - finding if the number I want to push is smaller than the smallest number in stack_b
	// - finding if the number I want to push is bigger than the biggest number in stack_b
	// - finding closest lower number in stack_b
	// - calculate the number of operations needed for push at the right place of stack_b (be aware of rr and rrr!) for each number from stack_a
	// -- could be calculated as ra and rb and then count how many times ra and rb are both there

	// choose the number with the lowest operations
	// push the number in stack_b
	// --- WHILE LOOP ENDS ---

	// --- WHILE LOOP STARTS---
	// start pushing back from stack_b to stack_a according to algo
	// - finding closest higher number in stack_b and rotate the stack_a until this number is on top
	// - push number from stack_b to stack_a
	// --- WHILE LOOP ENDS ---

	// rotate stack_a until lowest number at the top
	// DONE!
}