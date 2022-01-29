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

t_list *init_stack(char **input)
{
	int		i;
	int		*tmp;
	t_list	*stack;

	stack = NULL;
	i = -1;
	while (input[++i])
	{
		tmp = (void *)malloc(sizeof(int));
		*tmp = ft_atoi(input[i]);	
		ft_lstadd_back(&stack, ft_lstnew(tmp));
	}
	return (stack);
}

void	display_stack(t_list *stack)
{
	ft_lstiter(stack, &display_node);
	printf("done display stack\n");
}

void	display_node(void *data)
{
	ft_putnbr_fd(*(int *)data, 1);
	ft_putendl_fd("", 1);
}

