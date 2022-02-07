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

	char		**input;
	int			*array;

	int			input_size;
	int			to_split;
	int			split_size;
	int			median;
	int			from_top;
	int			from_bottom;


}	t_store;

// **** init_store.c ****
void	init_store(t_store *store);
void	create_stacks(char **input, t_list **stack_a, t_list **stack_b);
void	create_and_sort_array(t_store *store);
void	swap_int(int *i, int *j);

// **** push_swap.c ****
void	push_swap(t_store *store, char *option);
void	swap(t_list **stack, __attribute__((unused)) t_list **tmp);
void	push(t_list **dest, t_list **src_head);
void	rotate(t_list **stack, __attribute__((unused)) t_list **tmp);
void	r_rotate(t_list **stack, __attribute__((unused)) t_list **tmp);

// **** sort_stack.c ****
void	sort_stack(t_store *store);
void	push_a_to_b(t_store *store);
void	find_top_and_bottom(t_store *store, int num);
void	push_b_to_a(t_store *store);

// **** util_func.c ****
void	clear_before_exit(t_store *store);
void	exit_error(char *msg);
void	parse_input(char **arg, t_store *store);



/*
I am using linked list for creating
the stack a and stack b, these are
the functions for it
*/
void	display_stacks(t_store *store);
void	display_node(void *data);

void printArray(int arr[], int size);


#endif
