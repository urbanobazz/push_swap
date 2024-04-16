/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:53 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/19 13:19:12 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Calculate the size of the list */
int	stack_size(t_stack *stack)
{
	t_stack	*list;
	int		i;

	if (!stack)
		return (0);
	list = stack;
	i = 1;
	while (list->next != stack)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/* finds the smallest number in the list */
int	find_min(t_stack *stack)
{
	t_stack	*list;
	int		i;
	int		j;

	j = 0;
	list = stack;
	i = stack->nb;
	while (j < stack_size(stack))
	{
		if (list->nb < i)
			i = list->nb;
		list = list->next;
		j++;
	}
	return (i);
}

/* Finds the biggest number in the list */
int	find_max(t_stack *stack)
{
	t_stack	*list;
	int		i;
	int		j;

	j = 0;
	list = stack;
	i = stack->nb;
	while (j < stack_size(stack))
	{
		if (list->nb > i)
			i = list->nb;
		list = list->next;
		j++;
	}
	return (i);
}

/* Checks if the list is sorted */
int	is_sorted(t_stack *stack)
{
	t_stack	*list;

	list = stack;
	while (list->next != stack)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}
