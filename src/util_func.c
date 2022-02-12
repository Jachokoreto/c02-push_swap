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

void	exit_error(__attribute__((unused)) char *msg)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	clear_before_exit(t_store *store)
{
	int		i;

	ft_lstclear(&store->stacks[0], &free);
	ft_lstclear(&store->stacks[1], &free);
	i = -1;
	while (store->input[++i])
		free(store->input[i]);
	free(store->input);
	free(store->array);
}

void	parse_input(char **argv, t_store *store)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("");
	i = 0;
	while (argv[++i])
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, argv[i]);
		free(tmp2);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, " ");
		free(tmp2);
	}
	store->input = ft_split(tmp, ' ');
	free(tmp);
	check_input(store);
}

/**
 * @brief Check input for errors
 * Errors :
 * - arguments is not int
 * - arguments is not in int range
 * - duplicates in arguments(this check is done while sorting array)
 * Will also check if the input is already sorted,
 * by comparing the current and next number
 */
void	check_input(t_store *store)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	store->is_sorted = 1;
	while (store->input[++i])
	{
		j = 0;
		if (store->input[i][j] == '-')
			j++;
		while (store->input[i][j])
		{
			if (!ft_isdigit(store->input[i][j++]))
				exit_error("Input is not integer");
		}
		tmp = ft_itoa(ft_atoi(store->input[i]));
		if (ft_strncmp(store->input[i], tmp, ft_strlen(tmp)))
			exit_error("Input bigger/smaller than int");
		if (store->input[i + 1]
			&& ft_atoi(store->input[i]) > ft_atoi(store->input[i + 1]))
			store->is_sorted = 0;
		free(tmp);
	}
}
