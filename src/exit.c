/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:00:18 by jatan             #+#    #+#             */
/*   Updated: 2022/01/30 01:00:18 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(char *msg)
{
	ft_putendl_fd("Error\n", 1);
	ft_putendl_fd(msg, 1);
	exit (1);
}

void	clear_before_exit(char **input, t_store *store)
{
	int		i;

	ft_lstclear(&store->stacks[0], &free);
	ft_lstclear(&store->stacks[1], &free);
	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
	free(store->array);
}
