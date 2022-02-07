/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:54:55 by jatan             #+#    #+#             */
/*   Updated: 2022/02/07 19:13:01 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create stack a filled with int from array,
 * and stack b empty using linked list.
 * For every number, I malloc to store the int that
 * the new node's content will point to, then link it
 * after the previous nodes using ft_lstadd_back.
 *
 * @param input The array of input, each index is a number
 * @param stack_a
 * @param stack_b
 */
void	create_stacks(char **input, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		*tmp;

	*stack_a = NULL;
	*stack_b = NULL;
	i = -1;
	while (input[++i])
	{
		tmp = (void *)malloc(sizeof(int));
		*tmp = ft_atoi(input[i]);
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
	}
}

void	swap_int(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * @brief create and sort int array
 * I thought of using merge or quick sort, but
 * for the sake of simplicity, I will just use
 * bubble sort.
 */
void	create_and_sort_array(t_store *store)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = store->stacks[0];
	store->array = malloc(sizeof(int) * store->input_size);
	i = -1;
	while (tmp && tmp->content)
	{
		store->array[++i] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < store->input_size)
	{
		j = -1;
		while (++j < store->input_size - i - 1)
		{
			if (store->array[j] > store->array[j + 1])
				swap_int(&store->array[j], &store->array[j + 1]);
		}
	}
}

void	init_store(t_store *store)
{
	int	i;
	int	tmp;

	i = -1;
	while (store->input[++i])
		store->input_size = i + 1;
	create_stacks(store->input, &store->stacks[0], &store->stacks[1]);
	store->ps_funcs[0] = swap;
	store->ps_funcs[1] = rotate;
	store->ps_funcs[2] = push;
	store->ps_funcs[3] = r_rotate;
	create_and_sort_array(store);
	if (store->input_size >= 20)
		tmp = 20;
	else
		tmp = store->input_size;
	store->to_split = store->input_size / tmp;
	store->split_size = ((store->input_size % tmp) / store->to_split)
		+ store->input_size / store->to_split;
}
