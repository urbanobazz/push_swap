/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:32:44 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/22 16:36:32 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **stack_a, t_stack **stack_b);

int	main(int argc, char **argv)
{
	char	**array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	valid_args(&argc, argv, &array);
	stack_a = create_stack(stack_a, array);
	if (!(check_dup(stack_a)))
	{
		ft_free_array(array);
		ft_free_stack(&stack_a, stack_size(stack_a));
		ft_error("Error\n", 1);
	}
	index_stack(&stack_a);
	if (is_sorted(stack_a))
	{
		ft_free_array(array);
		ft_free_stack(&stack_a, stack_size(stack_a));
		exit (0);
	}
	sort(&stack_a, &stack_b);
	ft_free_array(array);
	ft_free_stack(&stack_a, stack_size(stack_a));
	ft_free_stack(&stack_b, stack_size(stack_b));
}

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) <= 3)
		sort_3(stack_a);
	else if (stack_size(*stack_a) <= 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/* void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		ft_printf("%i, ", temp->nb);
		temp = temp->next;
	}
	ft_printf("%i", temp->nb);
} */
/* ./push_swap $(shuf -i 0-100000 -n 500) |wc -l */
/* ARG="10 9 8 4 3 7 6 5 2 1 21 25 17 18 31";
 ./push_swap $ARG | ./checker_linux $ARG */
