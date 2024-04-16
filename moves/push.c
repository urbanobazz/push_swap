/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:14 by ubazzane          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:31 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	if (!(*stack_b))
		return ;
	temp_b = *stack_b;
	if ((*stack_b)->next == *stack_b && (*stack_b)->prev == *stack_b)
		*stack_b = NULL;
	else
	{
		temp_b->prev->next = temp_b->next;
		temp_b->next->prev = temp_b->prev;
		*stack_b = temp_b->next;
	}
	temp_b->next = (*stack_a);
	temp_b->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = temp_b;
	(*stack_a)->prev = temp_b;
	*stack_a = temp_b;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	if (!(*stack_a))
		return ;
	temp_a = *stack_a;
	temp_a->prev->next = temp_a->next;
	temp_a->next->prev = temp_a->prev;
	*stack_a = temp_a->next;
	if (!(*stack_b))
	{
		temp_a->prev = temp_a;
		temp_a->next = temp_a;
		*stack_b = temp_a;
	}
	else
	{
		temp_a->next = (*stack_b);
		temp_a->prev = (*stack_b)->prev;
		(*stack_b)->prev->next = temp_a;
		(*stack_b)->prev = temp_a;
		*stack_b = temp_a;
	}
	ft_putstr_fd("pb\n", 1);
}
