/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:46:48 by ubazzane          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:22 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_stack **stack, int write)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == *stack && (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->prev;
	if (write)
		ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_stack **stack, int write)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == *stack && (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->prev;
	if (write)
		ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int write)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (write)
		ft_putstr_fd("rrr\n", 1);
}
