/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:20 by jatan             #+#    #+#             */
/*   Updated: 2022/02/12 08:02:49 by jatan            ###   ########.fr       */
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

int	*get_stack_content(t_store *store)
{
	int		j;
	int		i;
	int		*num;
	t_list	*tmp;

	num = (int *)malloc(sizeof(int) * 3);
	if (!num)
		return (NULL);
	j = 0;
	tmp = store->stacks[0];
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

void	move_to_correct_position(t_store *store)
{
	int		pos;
	int		smaller_than;
	t_list	*tmp;

	tmp = store->stacks[0];
	smaller_than = 0;
	while (tmp)
	{
		if (*(int *)store->stacks[1]->content < *(int *)tmp->content)
			smaller_than++;
		tmp = tmp->next;
	}
	if (smaller_than == 0 || smaller_than )
	else
	{
		while (smaller_than-- > 0)

	}
		pos = *(int *)tmp->content;
	printf("%d\n", pos);
	find_from_top_and_from_bottom(store, pos, 1);
	while (*(int *)store->stacks[0]->content != pos)
	{
		if (store->from_top >= store->from_bottom)
			push_swap(store, "rra");
		else
			push_swap(store, "ra");
	}
}
