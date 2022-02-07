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
	t_store	store;

	if (argc < 2)
		exit_error("Run ./push_swap 5 2 3 1 ");
	parse_input(argv, &store);
	init_store(&store);
	sort_stack(&store);
	// display_stacks(&store);
	clear_before_exit(&store);
	return (0);
}
