/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:13:16 by jatan             #+#    #+#             */
/*   Updated: 2022/01/29 15:02:35 by jatan            ###   ########.fr       */
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

/**
 * The functions below are for debugging
 */

void	display_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("\033[0;34m=====STACK A=====\033[0m\n");
	ft_lstiter(stack_a, &display_node);
	printf("\033[0;35m=====STACK B=====\033[0m\n");
	ft_lstiter(stack_b, &display_node);
	ft_putendl_fd("++++++++++++++++++++++++", 1);
}

void	display_node(void *data)
{
	printf("%p : %d\n", data, *(int *)data);
}
