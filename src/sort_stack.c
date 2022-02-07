/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:52:07 by jatan             #+#    #+#             */
/*   Updated: 2022/02/07 01:40:34 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * TODO first i need a freaking plan, which i dont right now.
 * I think I can just follow one of the tutorials,
 * and in the meantime, brush up my understanding on complexity
 *
 * 	Plan:
 * 1. find median and split stack a to stack b (half or quarter)
 * 2. find the smallest and the biggest number from stack b
 * 3. determine the closest one
 * 4. take steps to move the closest one for pushing back to stack a
 *
 * how do i split the array?
 *
 */


void	push_a_to_b(t_store *store)
{
	int	i;
	int	moved;
	int	min;
	int	max;

	i = -1;
	while (++i < store->to_split)
	{
		moved = 0;
		min = store->array[store->split_size * i];
		max = store->array[min + store->split_size];
		while (moved <= store->split_size)
		{
			if (*(int *)store->stacks[0]->content >= min
				&& *(int *)store->stacks[0]->content <= max)
			{
				push_swap(store, "pb");
				moved++;
			}
			else
				push_swap(store, "ra");
		}

	}

}


void	sort_stack(t_store *store)
{
	push_a_to_b(store);
}

