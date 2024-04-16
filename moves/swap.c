/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:24:00 by ubazzane          #+#    #+#             */
/*   Updated: 2023/12/18 12:42:59 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack, int write)
{
	t_stack	*node;
	int		tmp;

	if (*stack != NULL && (*stack)->next != *stack)
	{
		node = *stack;
		tmp = node->nb;
		node->nb = node->next->nb;
		node->next->nb = tmp;
		tmp = node->index;
		node->index = node->next->index;
		node->next->index = tmp;
		if (write)
			ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack **stack, int write)
{
	t_stack	*node;
	int		tmp;

	if (*stack != NULL && (*stack)->next != *stack)
	{
		node = *stack;
		tmp = node->nb;
		node->nb = node->next->nb;
		node->next->nb = tmp;
		tmp = node->index;
		node->index = node->next->index;
		node->next->index = tmp;
		if (write)
			ft_putstr_fd("sb\n", 1);
	}
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, int write)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (write)
		ft_putstr_fd("ss\n", 1);
}
