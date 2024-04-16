/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:27:09 by ubazzane          #+#    #+#             */
/*   Updated: 2023/12/19 16:46:03 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

typedef struct node
{
	int			nb;
	int			index;
	struct node	*next;
	struct node	*prev;
}				t_stack;

void	swap_a(t_stack **stack, int write);
void	swap_b(t_stack **stack, int write);
void	swap_s(t_stack **stack_a, t_stack **stack_b, int write);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack, int write);
void	rotate_b(t_stack **stack, int write);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int write);
void	rev_rotate_a(t_stack **stack, int write);
void	rev_rotate_b(t_stack **stack, int write);
void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int write);
int		valid_args(int *argc, char **argv, char ***array);
int		make_array(int *argc, char **argv, char ***array);
int		is_valid(char *str, char **array);
int		fit_in_int(char *str);
void	ft_free_array(char **array);
t_stack	*create_stack(t_stack *stack, char **array);
void	fill_list(t_stack *stack, t_stack *new_node);
t_stack	*make_node(int value);
void	ft_free_stack(t_stack **stack, int size);
int		check_dup(t_stack *stack);
int		stack_size(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		is_sorted(t_stack *stack);
void	index_stack(t_stack **stack);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif
