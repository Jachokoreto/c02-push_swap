/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:52:06 by jatan             #+#    #+#             */
/*   Updated: 2022/01/29 22:52:06 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Notes:
 *
 */

int	main(int argc, char *argv[])
{
	char	**input;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (argc < 2)
		exit_error("Run ./push_swap 5 2 3 1");
	input = ft_split(argv[1], ' ');
	create_stacks(input, &stack_a, &stack_b);
	display_stacks(stack_a, stack_b);
	push_swap(&stack_a, &stack_b, "sb");
	push_swap(&stack_a, &stack_b, "pb");
	push_swap(&stack_a, &stack_b, "sb");
	push_swap(&stack_a, &stack_b, "rra");
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
	return (0);
}
