/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:52:08 by ubazzane          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:25 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack, int write)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == *stack && (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->next;
	if (write)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **stack, int write)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == *stack && (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->next;
	if (write)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int write)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (write)
		ft_putstr_fd("rr\n", 1);
}
