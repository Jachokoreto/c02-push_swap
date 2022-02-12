/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:54:55 by jatan             #+#    #+#             */
/*   Updated: 2022/02/13 01:04:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Initialize store that holds all the
 * neccessary data for this program.
 *
 * input_size:	the quantity of integer
 * ps_funcs:	an array of function pointers
 * 				- they are pointing to the functions
 * 				defined in push_swap.c
 * split_size:	the size of each chunk, 30 or lower
 * split_count:	quantity of chunks
 * last_split_size: for the remainders from previous chunks
 */
void	init_store(t_store *s)
{
	int	i;

	i = -1;
	while (s->input[++i])
		s->input_size = i + 1;
	create_stacks(s->input, &s->stacks[0], &s->stacks[1]);
	s->ps_funcs[0] = swap;
	s->ps_funcs[1] = rotate;
	s->ps_funcs[2] = push;
	s->ps_funcs[3] = r_rotate;
	create_and_sort_array(s);
	if (s->input_size >= 30)
		s->split_size = 30;
	else
		s->split_size = s->input_size;
	s->split_count = s->input_size / s->split_size;
	s->last_split_size = s->input_size % s->split_size;
	if (s->last_split_size > 0)
		s->split_count++;
}

/**
 * @brief
 * Create stack_a filled with int from array,
 * and stack_b empty using linked list.
 * For every number, it malloc to store the int that
 * the new node's content will point to, then link it
 * after the previous nodes using ft_lstadd_back.
 *
 * @param input The array of input, each index is a number
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
 * @brief
 * Create and sort int array
 * I thought of using merge or quick sort, but
 * for the sake of simplicity, I just use bubble sort.
 * Creating this sorted int array for later moving reference
 * While doing bubble sort, it will check if thers duplicates.
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
			if (store->array[j] == store->array[j + 1])
				exit_error("Input have duplicates");
		}
	}
}


