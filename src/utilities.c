/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:07:45 by jatan             #+#    #+#             */
/*   Updated: 2022/02/13 00:48:38 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printIntArray(int arr[], int size)
{
    int i;

    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printStrArray(char *arr[])
{
    int i;

	i = -1;
    while (arr[++i])
        ft_putendl_fd(arr[i], 1);
}


char	*format_node(t_list *stack_a, t_list *stack_b);

void	display_stacks(t_store *store)
{
	char	*formatted_res;

	printf("\033[0;34m=== STACK A ===\033[0m");
	printf("\033[0;35m === STACK B ===\033[0m\n");
	formatted_res = format_node(store->stacks[0], store->stacks[1]);
	printf("%s", formatted_res);
	printf("\033[0;34m================\033[0m");
	printf("\033[0;35m================\033[0m\n\n");

	free(formatted_res);
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
