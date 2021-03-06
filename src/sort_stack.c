/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:52:07 by jatan             #+#    #+#             */
/*   Updated: 2022/02/16 12:47:43 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Driver function to sort the stack.
 *
 * Will run the usual sort when there's more than 5 elements.
 * If not, will run the small sort and rotate it to make sure
 * the smallest is at the top.
 */
void	sort_stack(t_store *store)
{
	int		i;

	if (store->input_size > 5)
	{
		push_a_to_b(store);
		push_b_to_a(store);
		return ;
	}
	if (store->input_size == 2)
	{
		push_swap(store, "sa");
		return ;
	}
	i = -1;
	while (store->input_size - (++i) > 3)
		push_swap(store, "pb");
	small_sort(store);
	while (*(int *)store->stacks[0]->content != store->array[0])
		push_swap(store, "ra");
}

/**
 * @brief Ironically, this small sort is more complicated than the big one.
 * Had to make two functions for this,
 * One for the 3 number stack and one for the 4th and 5th number.
 *
 * Sort the elements in stack_a first following the possible 5 cases method.
 * Then if theres elements in stack_b, rotate stack_a to correct position
 * and push elements from b to a, while keep tracking the smallest element too.
 */
void	small_sort(t_store *s)
{
	int		*num;
	int		small;

	while (1)
	{
		num = get_stack_content_rank(s, 0);
		if (num[0] < num[1] && num[1] < num[2])
			break ;
		if (num[0] > num[1] && num[0] > num[2] && num[2] > num[1])
			push_swap(s, "ra");
		else if (num[0] < num[1] && num[0] > num[2])
			push_swap(s, "rra");
		else
			push_swap(s, "sa");
		free(num);
	}
	free(num);
	small = *(int *)s->stacks[0]->content;
	while (s->stacks[1])
	{
		move_to_correct_position(s, small);
		push_swap(s, "pa");
		if (*(int *)s->stacks[0]->content < small)
			small = *(int *)s->stacks[0]->content;
	}
}

/**
 * @brief Split the stack according to the properties set in inti_store()
 * TLDR: stack will be split into stacks with <=20 elements. Each split is
 * numbers in between a certain range. On the last loop it will check if
 * there's remainder, and adjust the loop counter to remainder.
 *
 * moved:		to keep track how many elements it moved
 * split_size:	loop counter to ensure it moved the correct amount for each group
 */
void	push_a_to_b(t_store *s)
{
	int	i;
	int	moved;
	int	split_size;

	split_size = s->split_size;
	i = -1;
	while (++i < s->split_count)
	{
		if (i + 1 == s->split_count && s->last_split_size > 0)
			split_size = s->last_split_size;
		moved = 0;
		while (moved < split_size)
		{
			if (*(int *)s->stacks[0]->content >= s->array[s->split_size * i]
				&& *(int *)s->stacks[0]->content
				<= s->array[s->split_size * i + split_size - 1])
			{
				push_swap(s, "pb");
				moved++;
			}
			else
				push_swap(s, "ra");
		}
	}
}

/**
 * @brief After pushing all elements to b in groups,
 * For each groups, it will find the biggest number and calculate
 * the required steps to reach from bottom and from top, then
 * rotate in the lesser direction, then push it back to a.
 *
 * moved:		keep track how many elements has moved
 * move_idx:	the target element, current biggest in group
 * 				- calculate by offsetting moved elements and current
 * 				split group from the descending order
 */
void	push_b_to_a(t_store *store)
{
	int		i;
	int		moved;
	int		move_idx;

	i = -1;
	while (++i < store->split_count)
	{
		moved = 0;
		while (store->stacks[1] && moved < store->split_size)
		{
			move_idx = store->input_size - moved - (store->split_size * i) - 1;
			find_from_top_and_from_bottom(store, store->array[move_idx], 1);
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
