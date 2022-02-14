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
		return (0);
	parse_and_check_input(argv, &store);
	init_store(&store);
	if (store.is_sorted != 1)
		sort_stack(&store);
	clear_before_exit(&store);
	return (0);
}
