/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:54:55 by jatan             #+#    #+#             */
/*   Updated: 2022/02/02 11:08:17 by jatan            ###   ########.fr       */
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

void	create_sorted_array(t_store *store)
{
	t_list	*tmp;
	int		i;

	tmp = store->stacks[0];
	store->array = malloc(sizeof(int) * store->input_size);
	i = -1;
	while (tmp->next)
	{
		store->array[++i] = tmp->content;
		tmp = tmp->next;
	}
}

void	init_store(char **input, t_store *store)
{
	int	i;

	create_stacks(input, &store->stacks[0], &store->stacks[1]);
	store->ps_funcs[0] = swap;
	store->ps_funcs[1] = rotate;
	store->ps_funcs[2] = push;
	store->ps_funcs[3] = r_rotate;
	i = -1;
	while (input[++i])
		store->input_size = i + 1;
}
