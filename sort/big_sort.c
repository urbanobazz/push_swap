/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:17:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/19 16:12:28 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max_bits_needed(t_stack **stack);
static int	find_max_index(t_stack *stack);

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	list_a = *stack_a;
	size = stack_size(*stack_a);
	max_bits = max_bits_needed(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			list_a = *stack_a;
			if (((list_a->index >> i) & 1) == 1)
				rotate_a(stack_a, 1);
			else
				push_b(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}

/*finds the maximum number of bits needed to store the biggest index
by checking how many times it can be divided by 2 before reaching zero */
static int	max_bits_needed(t_stack **stack)
{
	int		max;
	int		max_bits;

	max = find_max_index(*stack);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* Looks for the highest index */
static int	find_max_index(t_stack *stack)
{
	t_stack	*list;
	int		i;
	int		j;

	j = 0;
	list = stack;
	i = stack->index;
	while (j < stack_size(stack))
	{
		if (list->index > i)
			i = list->index;
		list = list->next;
		j++;
	}
	return (i);
}
