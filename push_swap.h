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
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


void	push_swap(t_list **stack_a, t_list **stack_b, char *option);
void	exit_error(char *msg);

/*
I am using linked list for creating
the stack a and stack b, these are
the functions for it
*/
void	create_stacks(char **input, t_list **stack_a, t_list **stack_b);
void	display_stacks(t_list *stack_a, t_list *stack_b);
void	display_node(void *data);

#endif
