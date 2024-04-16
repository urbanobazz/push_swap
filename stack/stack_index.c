/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:58:29 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/19 13:17:52 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*next_min(t_stack **stack);

/* Adds indexes to the the nodes in ascending order */
void	index_stack(t_stack **stack)
{
	t_stack	*list;
	int		index;

	index = 0;
	list = next_min(stack);
	while (index < stack_size(*stack))
	{
		list->index = index;
		list = next_min(stack);
		index++;
	}
}

/* Looks for the the next smallest number,
AKA: the smallest that still has the index -1 */
static t_stack	*next_min(t_stack **stack)
{
	t_stack	*list;
	t_stack	*min;
	int		i;

	list = *stack;
	min = NULL;
	i = 0;
	while (i < stack_size(*stack))
	{
		if ((list->index == -1) && (!min || list->nb < min->nb))
			min = list;
		list = list->next;
		i++;
	}
	return (min);
}
