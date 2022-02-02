/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:52:23 by jatan             #+#    #+#             */
/*   Updated: 2022/01/29 22:52:23 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef void	(*t_ps_funcs)(t_list **stack_a, t_list **stack_b);


typedef struct s_store {
	t_list		*stacks[2];

	t_ps_funcs	ps_funcs[4];

	int			*array;
	int			input_size;
	int			median;

}	t_store;

void	init_store(char **input, t_store *store);
void	push_swap(t_store *store, char *option);
void	exit_error(char *msg);


/**** PUSH_SWAP FUNCTIONS ****/
void	swap(t_list **stack, __attribute__((unused)) t_list **tmp);
void	push(t_list **dest, t_list **src_head);
void	rotate(t_list **stack, __attribute__((unused)) t_list **tmp);
void	r_rotate(t_list **stack, __attribute__((unused)) t_list **tmp);

/*
I am using linked list for creating
the stack a and stack b, these are
the functions for it
*/
void	create_stacks(char **input, t_list **stack_a, t_list **stack_b);
void	display_stacks(t_store *store);
void	display_node(void *data);

#endif