/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:58 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int	find_next_max(t_stack *stack)
{
	int	pos;
	int	max;

	pos = 0;
	max = stack->value;
	while (stack->next != NULL)
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
	while (stack->next != NULL)
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

void	assign_positions(t_stack *stack)
{
	int	position;

	position = 0;
	while(stack != NULL)
	{
		stack->index = position;
		position++;
		stack = stack->next;
	}
}

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	assign_positions(*stack_a);
	assign_positions(*stack_b);
}

int	ordered(t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
