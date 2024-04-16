/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:31:43 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/19 13:15:46 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Create the head node */
t_stack	*create_stack(t_stack *stack, char **array)
{
	int	i;

	stack = make_node(ft_atoi(array[0]));
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
		fill_list(stack, make_node(ft_atoi(array[i++])));
	return (stack);
}

/* fill the list with the following nodes */
void	fill_list(t_stack *stack, t_stack *new_node)
{
	t_stack	*head;

	if (stack->next == stack && stack->prev == stack)
	{
		stack->next = new_node;
		stack->prev = new_node;
		new_node->prev = stack;
		new_node->next = stack;
		return ;
	}
	head = stack;
	new_node->prev = head->prev;
	new_node->next = head;
	head->prev->next = new_node;
	head->prev = new_node;
}

/* create a new node */
t_stack	*make_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nb = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/* Check the list for duplicate values */
int	check_dup(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*head;

	head = stack;
	while (head->next != stack)
	{
		temp = head->next;
		while (temp->next != head)
		{
			if (temp->nb == head->nb)
				return (0);
			temp = temp->next;
		}
		head = head->next;
	}
	temp = head->next;
	while (temp != head)
	{
		if (temp->nb == head->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* Frees the stack */
void	ft_free_stack(t_stack **stack, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (i < size - 1)
	{
		temp = temp->next;
		free(temp->prev);
		i++;
	}
	free(temp);
}
