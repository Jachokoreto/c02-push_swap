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
 * The functions below are for debugging
 */

void	display_stacks(t_store *store)
{
	char	*formatted_res;

	printf("\e[1;1H\e[2J");
	printf("\033[0;34m=== STACK A ===\033[0m");
	// ft_lstiter(stack_a, &display_node);
	printf("\033[0;35m === STACK B ===\033[0m\n");
	// ft_lstiter(stack_b, &display_node);
	formatted_res = format_node(store->stacks[0], store->stacks[1]);
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
