/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:20 by jatan             #+#    #+#             */
/*   Updated: 2022/02/14 13:49:10 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Find how many steps to reach target from top and from bottom.
 * Go thru the linked list and increment from_top
 * until finding the target int, then go thru the linked list and
 * increment from_bottom until reaching the end.
 *
 * @param store
 * @param num The target integer
 * @param stack_ch Which stack to look in
 */
void	find_from_top_and_from_bottom(t_store *store, int num, int stack_ch)
{
	t_list	*tmp;

	tmp = store->stacks[stack_ch];
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

/**
 * @brief
 * This is for the small sort.
 * It calculates the ranking/placing of each element
 * in the stack by comparing the element with the sorted
 * array in store.
 *
 * @param store
 * @param stack_ch
 * @return int* an array of int corresponding to elements
 */
int	*get_stack_content_rank(t_store *store, int stack_ch)
{
	int		j;
	int		i;
	int		*num;
	t_list	*tmp;

	num = malloc(sizeof(int) * ft_lstsize(store->stacks[stack_ch]) + 1);
	if (!num)
		return (NULL);
	j = 0;
	tmp = store->stacks[stack_ch];
	while (tmp)
	{
		i = -1;
		while (++i < store->input_size)
			if (*(int *)tmp->content == store->array[i])
				num[j++] = i;
		tmp = tmp->next;
	}
	return (num);
}

/**
 * @brief
 * Make necessary rotations before pushing elements from b to a
 * If the element in stack b is biggest or the smallest number,
 * rotate to the smallest element in stack a
 * else rotate to the element thats after element b.
 * But if the next element is not available, will either
 * rotate to the one after or to the smallest element
 *
 * @param store
 * @param small the smallest element in stack a
 */
void	move_to_correct_position(t_store *store, int small)
{
	int		*num;
	int		pos;

	num = get_stack_content_rank(store, 1);
	if (num[0] == 0 || num[0] == store->input_size - 1)
		pos = small;
	else
		pos = store->array[num[0] + 1];
	if (store->stacks[1]->next
		&& *(int *)store->stacks[1]->next->content == pos)
	{
		if (num[0] + 2 < store->input_size)
			pos = store->array[num[0] + 2];
		else
			pos = small;
	}
	find_from_top_and_from_bottom(store, pos, 0);
	while (*(int *)store->stacks[0]->content != pos)
	{
		if (store->from_top >= store->from_bottom)
			push_swap(store, "rra");
		else
			push_swap(store, "ra");
	}
	free(num);
}
