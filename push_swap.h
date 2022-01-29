#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// typedef struct s_node {
// 	void	*data;
// 	struct s_node *next;
// }				t_node;

void	push_swap(char *num_list);
void	exit_error(char *msg);

/* 
I am using linked list for creating
the stack a and stack b, these are
the functions for it
*/
t_list	*init_stack(char **input);
void	display_stack(t_list *stack);
void	display_node(void *data);

#endif