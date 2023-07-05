/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/05 12:43:45 by gvigilan         ###   ########.fr       */
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

int count_moves(t_stack *node, t_stack *a, t_stack *b)
{
	t_stack *head;
	int	i;

	head = a;
	i = 0;
	while (head->value != next_last_a(node, a)->value && head->next != NULL)
	{
		i++;
		head = head->next;
	}
	if (head->index > ft_stacksize(a)/2 && node->index < ft_stacksize(b)/2)
		return (ft_stacksize(a) - i + node->index + 1);
	else if (node->index > ft_stacksize(b)/2 && head->index < ft_stacksize(a)/2)
		return (i + ft_stacksize(b) - node->index + 1);
	else if (head->index < ft_stacksize(a)/2 && node->index < ft_stacksize(b)/2)
		return (i + node->index + 1);
	else
		return (ft_stacksize(a) - i + ft_stacksize(b) - node->index + 1);
}

void	assign_positions(t_stack *stack)
{
	t_stack	*head;
	int	position;

	position = 0;
	head = stack;
	while(head != NULL)
	{
		head->index = position;
		position++;
		head = head->next;
	}
}

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = *stack_a;
	while (ft_stacksize(*stack_a) > 3)
	{
		head = *stack_a;
		if ((*stack_b) != NULL)
		{
			while (head->next->value > head->value && !(max_node(*stack_b)->value < head->value || min_node(*stack_b)->value > head->value))
			{
				rotate(stack_a, 1);
				head = *stack_a;
			}
		}
		push(stack_a, stack_b, 1);
		if (ordered(*stack_a))
			break;
	}
	assign_positions(*stack_a);
	assign_positions(*stack_b);
	if (ft_stacksize(*stack_a) == 3)
		order_3(stack_a);
}
