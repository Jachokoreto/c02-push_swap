/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:36:04 by jatan             #+#    #+#             */
/*   Updated: 2022/01/29 19:36:04 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * *Swap the content of the first two nodes
 * As the linked list struct holds a void pointer,
 * I have to cast it into int pointer,
 * then dereference it to assign new value
 *
 *    *(int *)head->content
 *    ^ ^^^^^---- this is casting
 *    |---------- this is dereference
 *
 * @param head Pointer to the stack for swap
 */
void	swap(t_list **stack, __attribute__((unused)) t_list **tmp)
{
	int		temp;
	t_list	*head;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	temp = *(int *)head->content;
	*(int *)head->content = *(int *)head->next->content;
	*(int *)head->next->content = temp;
}

/**
 * @brief
 * *Push the first element to the opposite stack
 * First need to change the src_head from current node
 * to the 2nd node, then I utilize the ft_lstadd_front
 * function to add the 1st node(stored in temp) from
 * src stack to dest stack.
 *
 * @param src_head Pointer to the stack that need to push
 * @param dest Pointer to the stack to push into
 */
void	push(t_list **dest, t_list **src_head)
{
	t_list	*temp;

	if (!*src_head)
		return ;
	temp = *src_head;
	*src_head = temp->next;
	ft_lstadd_front(dest, temp);
}

/**
 * @brief
 * *Shiff all elements up by 1
 * In linked list, we can just move the 1st node
 * down to last. So again, set the head to 2nd node,
 * then disconnect the moving node's next link,
 * use ft_lstadd_back to put it at the end of the stack
 *
 * @param stack Pointer to the stack for operation
 */
void	rotate(t_list **stack, __attribute__((unused)) t_list **tmp)
{
	t_list	*temp;

	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

/**
 * @brief
 * *Shiff all elements down by 1
 * Similar as rotate(), but this one need to first find
 * the last and 2nd last node, disconnect the 2nd last node,
 * add a new node with the same content as last node,
 * remove the last node.
 *
 * @param stack Pointer to the stack for operation
 */
void	r_rotate(t_list **stack, __attribute__((unused)) t_list **tmp)
{
	t_list	*temp;
	t_list	*prev;

	temp = *stack;
	while (temp && temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	ft_lstadd_front(stack, ft_lstnew(temp->content));
	prev->next = NULL;
	free(temp);
}

/**
 * @brief
 * *Menu for the push_swap functions
 * By storing the 4 functions in a function pointer array and
 * the 2 stacks in a stack_array, I can dynamicly call the functions
 * according to the input.
 *
 * if input length is 2 (all except rra/rrb/rrr)
 * func_ch is s/r/p -> 0/1/2, find the pos of input[0] in char *menu
 * stack_ch is the stack option, either a or b, minus by 'a', I get 0 or 1
 *
 * @param stack_a Pointer to the stack_a
 * @param stack_b Pointer to the stack_b
 * @param input The input, s/r/p/rr + a/b/?
 */
void	push_swap(t_store *store, char *input)
{
	char	*menu;
	int		func_ch;
	int		stack_ch;

	menu = ft_strdup("srp");
	ft_putendl_fd(input, 1);
	if (ft_strlen(input) == 2)
		func_ch = ft_strchr(menu, input[0]) - &menu[0];
	else
		func_ch = 3;
	stack_ch = input[ft_strlen(input) - 1] - 'a';
	store->ps_funcs[func_ch](&store->stacks[stack_ch],
		&store->stacks[(stack_ch + 1) % 2]);
	if (stack_ch > 1)
		store->ps_funcs[func_ch](&store->stacks[1], &store->stacks[0]);
	display_stacks(store);
	free(menu);
}
