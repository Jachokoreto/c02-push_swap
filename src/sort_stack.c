/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:52:07 by jatan             #+#    #+#             */
/*   Updated: 2022/02/08 17:55:08 by jatan            ###   ########.fr       */
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

/**
 * @brief Driver function to sort the stack.
 */
void	sort_stack(t_store *store)
{
	int	i;

	if (store->input_size > 5)
	{
		push_a_to_b(store);
		push_b_to_a(store);
		return ;
	}
	i = 0;
	while (store->input_size - ++i > 3)
		push_swap(store, "pb");
	if (store->stacks[1])
	{
		
	}
}

/**
 * @brief Split the stack according to the properties set in inti_store()
 * TLDR: stack will be split into stacks with <=20 elements. Each split is
 * numbers in between a certain range.
 * the last call will happen if theres remainder from dividing 20
 * 
 * @param store 
 */
void	push_a_to_b(t_store *store)
{
	int	i;

	i = -1;
	while (++i < store->to_split)
		split_stack(store, i, store->split_size);
	if (store->last_split_size > 0)
		split_stack(store, i, store->last_split_size);
}

void	split_stack(t_store *store, int i, int split_size)
{
	int	moved;
	int	min;
	int	max;

	moved = 0;
	min = store->array[store->split_size * i];
	max = store->array[store->split_size * i + split_size - 1];
	while (moved < split_size)
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

/**
 * @brief After pushing all elements to b in groups,
 * For each groups, I will find the biggest number and calculate 
 * the required steps to reach from bottom and from top, then take 
 * rotate in the lesser direction, then push it back to a.
 */
void	push_b_to_a(t_store *store)
{
	int		i;
	int		moved;
	int		move_idx;

	if (store->last_split_size > 0)
		store->to_split++;
	i = -1;
	while (++i < store->to_split)
	{
		moved = 0;
		while (store->stacks[1] && moved < store->split_size)
		{
			move_idx = store->input_size - moved - (store->split_size * i) - 1;
			find_top_and_bottom(store, store->array[move_idx]);
			while (*(int *)store->stacks[1]->content != store->array[move_idx])
			{
				if (store->from_top >= store->from_bottom)
					push_swap(store, "rrb");
				else
					push_swap(store, "rb");
			}
			push_swap(store, "pa");
			moved++;
		}
	}
}

void	find_top_and_bottom(t_store *store, int num)
{
	t_list	*tmp;

	tmp = store->stacks[1];
	store->from_top = 0;
	store->from_bottom = 0;
	while (tmp && *(int *)tmp->content != num)
	{
		tmp = tmp->next;
		store->from_top++;
	}
	while (tmp)
	{
		tmp = tmp->next;
		store->from_bottom++;
	}
}
