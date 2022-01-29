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
 * @param head Pointer to the node for swap
 */
void	swap(t_list *head)
{
	int	tmp;

	tmp = *(int *)head->content;
	*(int *)head->content = *(int *)head->next->content;
	*(int *)head->next->content = tmp;
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
void	push(t_list **src_head, t_list **dest)
{
	t_list	*temp;

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
void	rotate(t_list **stack)
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
void	r_rotate(t_list **stack)
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
 * still thinking what better way i can do this
 *
 * @param stack_a Pointer to the stack_a
 * @param stack_b Pointer to the stack_b
 * @param option The option of which function to use
 */
void	push_swap(t_list **stack_a, t_list **stack_b, char *option)
{
	if (!ft_strncmp(option, "sa", 2))
		swap(*stack_a);
	if (!ft_strncmp(option, "pa", 2))
		push(stack_a, stack_b);
	if (!ft_strncmp(option, "ra", 2))
		rotate(stack_a);
	if (!ft_strncmp(option, "rra", 3))
		r_rotate(stack_a);
	ft_putendl_fd(option, 1);
	display_stacks(*stack_a, *stack_b);
}
