/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:20 by jatan             #+#    #+#             */
/*   Updated: 2022/02/09 15:12:09 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_from_top_and_from_bottom(t_store *store, int num)
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

int	*compare_elements_and_find_pos(t_store *store)
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
