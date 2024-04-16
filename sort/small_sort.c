/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:38:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/19 16:16:06 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack **stack)
{
	int	biggest;

	if (is_sorted(*stack))
		return ;
	biggest = find_max(*stack);
	if ((*stack)->nb == biggest)
		rotate_a(stack, 1);
	else if ((*stack)->next->nb == biggest)
		rev_rotate_a(stack, 1);
	if ((*stack)->nb > (*stack)->next->nb)
		swap_a(stack, 1);
}

/*pushes the the biggest and smallest number to b, then sort 3 remaining.
then pushes the numbers back to way, in their correct place*/
void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	if (is_sorted(*stack_a))
		return ;
	min = find_min(*stack_a);
	max = find_max(*stack_a);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->nb == min || (*stack_a)->nb == max)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, 1);
	}
	sort_3(stack_a);
	while (stack_size(*stack_b) > 0)
	{
		push_a(stack_a, stack_b);
		if (!is_sorted(*stack_a))
			rotate_a(stack_a, 1);
	}
}
