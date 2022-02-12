/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:20 by jatan             #+#    #+#             */
/*   Updated: 2022/02/12 16:56:57 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*get_stack_content_rank(t_store *store, int stack_ch)
{
	int		j;
	int		i;
	int		*num;
	t_list	*tmp;

	num = malloc(sizeof(int) * ft_lstsize(store->stacks[stack_ch]));
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

void	move_to_correct_position(t_store *store, int small)
{
	int		smaller_than;
	t_list	*tmp;
	int		*num;
	int		pos;

	tmp = store->stacks[0];
	smaller_than = 0;
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
}
