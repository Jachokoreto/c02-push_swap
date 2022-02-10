/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:52:07 by jatan             #+#    #+#             */
/*   Updated: 2022/02/10 12:22:12 by jatan            ###   ########.fr       */
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
	int		i;

	if (store->input_size > 5)
	{
		push_a_to_b(store);
		push_b_to_a(store);
		return ;
	}
	i = -1;
	while (store->input_size - (++i) > 3)
		push_swap(store, "pb");
	small_sort(store);
}

void	small_sort(t_store *s)
{
	int		*num;
	int		move_to;
	int		i;
	int		size;

	while (1)
	{
		num = compare_elements_and_find_pos(s);
		if (num[0] < num[1] && num[1] < num[2])
			break ;
		if (num[0] > num[1] && num[0] > num[2] && num[2] > num[1])
			push_swap(s, "ra");
		else if (num[0] < num[1] && num[0] > num[2])
			push_swap(s, "rra");
		else
			push_swap(s, "sa");
	}
	size = 3;
	display_stacks(s);

	while (s->stacks[1])
	{
		move_to = 0;
		while (*(int *)s->stacks[1]->content != s->array[move_to++])
		if (move_to >= s->input_size)
			move_to = s->input_size - 1;
		ft_printf("%d, %d\n", move_to, s->input_size);
		i = -1;
		while (*(int *)s->stacks[0]->content != s->array[move_to] && ++i < size)
			push_swap(s, "ra");
		push_swap(s, "pa");
		size++;
	}
	display_stacks(s);
	while (*(int *)s->stacks[0]->content != s->array[0])
		push_swap(s, "rra");
}

/**
 * @brief Split the stack according to the properties set in inti_store()
 * TLDR: stack will be split into stacks with <=20 elements. Each split is
 * numbers in between a certain range.
 * On the last loop it will check if there's remainder, 
 * and adjust the loop counter to remainder.
 * 
 * moved = to keep track how many elements it moved
 * split_size = loop counter to ensure it moved the correct amount for each group
 */
void	push_a_to_b(t_store *s)
{
	int	i;
	int	moved;
	int	split_size;

	split_size = s->split_size;
	i = -1;
	while (++i < s->to_split)
	{
		if (i + 1 == s->to_split && s->last_split_size > 0)
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
 * For each groups, I will find the biggest number and calculate
 * the required steps to reach from bottom and from top, then take
 * rotate in the lesser direction, then push it back to a.
 */
void	push_b_to_a(t_store *store)
{
	int		i;
	int		moved;
	int		move_idx;

	i = -1;
	while (++i < store->to_split)
	{
		moved = 0;
		while (store->stacks[1] && moved < store->split_size)
		{
			move_idx = store->input_size - moved - (store->split_size * i) - 1;
			find_from_top_and_from_bottom(store, store->array[move_idx]);
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
