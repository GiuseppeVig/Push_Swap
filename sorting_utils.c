/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/10 14:16:02 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	find_next_max(t_stack *stack)
{
	int	pos;
	int	max;

	pos = 0;
	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
		{
			max = stack->value;
			pos = stack->index;
		}
		stack = stack->next;
	}
	return (pos);
}

int	find_next_min(t_stack *stack)
{
	int	pos;
	int	min;

	pos = 0;
	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			pos = stack->index;
		}
		stack = stack->next;
	}
	return (pos);
}

int	count_moves(t_stack *node, t_stack *a, t_stack *b)
{
	t_stack	*head;
	int		size_a;
	int		size_b;
	int		i;

	head = a;
	i = 0;
	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	while (head->value != next_last_a(node, a)->value && head->next != NULL)
	{
		i++;
		head = head->next;
	}
	if (head->index > size_a / 2 && node->index < size_b / 2)
		return (size_a - i + node->index + 1);
	else if (node->index > size_b / 2 && head->index < size_a / 2)
		return (i + size_b - node->index + 1);
	else if (head->index < size_a / 2 && node->index < size_b / 2)
		return (i + node->index + 1);
	else
		return (size_a - i + size_b - node->index + 1);
}

void	assign_positions(t_stack *stack)
{
	t_stack	*head;
	int		position;

	position = 0;
	head = stack;
	while (head != NULL)
	{
		head->index = position;
		position++;
		head = head->next;
	}
}

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stacksize(*stack_a) > 3 && !ordered(*stack_a))
		push(stack_a, stack_b, 1);
	if (ft_stacksize(*stack_a) == 3)
		order_3(stack_a);
}
