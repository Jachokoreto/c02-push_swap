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

// define push_swap functions
typedef void	(*t_ps_funcs)(t_list **stack_a, t_list **stack_b);

typedef struct s_store {
	t_list		*stacks[2];

	t_ps_funcs	ps_funcs[4];

	char		**input;
	int			*array;

	int			is_sorted;

	int			input_size;
	int			split_count;
	int			split_size;
	int			last_split_size;

	int			from_top;
	int			from_bottom;

}	t_store;

// **** util_func.c ****
void	clear_before_exit(t_store *store);
void	exit_error( __attribute__((unused)) char *msg);
void	parse_and_check_input(char **arg, t_store *store);
void	check_input(t_store *store);

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
void	small_sort(t_store *store);
void	push_a_to_b(t_store *store);
void	push_b_to_a(t_store *store);

// **** sort_stack_utils.c ****
void	find_from_top_and_from_bottom(t_store *store, int num, int stack_ch);
int		*get_stack_content_rank(t_store *store, int stack_ch);
void	move_to_correct_position(t_store *store, int small);

/*
I am using linked list for creating
the stack a and stack b, these are
the functions for it
*/
// void	display_stacks(t_store *store);
// void	display_node(void *data);

// void		printIntArray(int arr[], int size);
// void		printStrArray(char *arr[]);

#endif
