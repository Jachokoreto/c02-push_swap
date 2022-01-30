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

char	*format_node(t_list *stack_a, t_list *stack_b);


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
	char	*formatted_res;

	printf("\033[0;34m=== STACK A ===\033[0m");
	// ft_lstiter(stack_a, &display_node);
	printf("\033[0;35m === STACK B ===\033[0m\n");
	// ft_lstiter(stack_b, &display_node);
	formatted_res = format_node(stack_a, stack_b);
	printf("%s", formatted_res);
	printf("\033[0;34m================\033[0m");
	printf("\033[0;35m================\033[0m\n\n");

	free(formatted_res);
}

void	display_node(void *data)
{
	printf("%p : %d\n", data, *(int *)data);
}

char	*format_node(t_list *stack_a, t_list *stack_b)
{
	char	*str;
	char	*tmp;
	char	*num;



	str = ft_strdup("");
	while (stack_a || stack_b)
	{
		tmp = str;
		str = ft_strjoin(tmp, "\t");
		free(tmp);
		if (stack_a && stack_a->content)
		{
			tmp = str;
			num = ft_itoa(*(int *)stack_a->content);
			str = ft_strjoin(tmp, num);
			free(tmp);
			free(num);
			stack_a = stack_a->next;
		}
		tmp = str;
		str = ft_strjoin(tmp, "\t\t");
		free(tmp);
		if (stack_b && stack_b->content)
		{
			tmp = str;
			num = ft_itoa(*(int *)stack_b->content);
			str = ft_strjoin(tmp, num);
			free(tmp);
			free(num);
			stack_b = stack_b->next;
		}
		tmp = str;
		str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	return (str);
}
