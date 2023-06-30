/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:46:54 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/01 00:38:05 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_stack_a(t_stack **a, t_stack *node)
{
	t_stack *head;
	int		i;

	head = *a;
	i = 0;
	if (node->value > max_node(*a)->value)
		reverse_rotate(a, 1);
	while (node->value > head->value)
	{
		i++;
		head = head->next;
	}
	while (i <= ft_stacksize(*a)/2 && i != 0)
	{
		rotate(a, 1);
		i--;
	}
	while (i > ft_stacksize(*a)/2)
	{
		reverse_rotate(a, 1);
		i--;
	}
}

void	bring_node_on_top(t_stack **stack_b, t_stack *node)
{
	t_stack *head;
	while (head->value != node->value)
	{
		head = *stack_b;
		if (head->value == node->value)
			break;
		if (node->index < ft_stacksize(*stack_b)/2)
			rotate(stack_b, 1);
		else
			reverse_rotate(stack_b, 1);
	}
}

void	move_stacks(t_stack **a, t_stack **b, t_stack *node)
{
	t_stack *head;

	while ((*b)->value != node->value)
	{
		head = *a;
		if (node->value > max_node(*a)->value || node->value < min_node(*a)->value)
			bring_node_on_top(b, node);
		while (head->value < node->value && (*b)->value != node->value)
		{
			if (node->index < ft_stacksize(*b)/2)
				rotate_both(a, b);
			else
				reverse_rotate_both(a, b);
		}
		while (head->value > node->value && (*b)->value != node->value)
		{
			if (node->index > ft_stacksize(*b)/2)
				rotate_both(a, b);
			else
				reverse_rotate_both(a, b);
		}
		bring_node_on_top(b, node);
	}
}

void	order_stacks(t_stack **a, t_stack **b)
{
	t_stack *next_node;

	while (ft_stacksize(*b) != 0)
	{
		next_node = search_next_node(*a, *b);
		move_stacks(a, b, next_node);
		adjust_stack_a(a, next_node);
		push(b, a, 2);
		assign_positions(*a);
		assign_positions(*b);
	}
	while (!ordered(*a))
	{
		rotate(a, 1);
	}
}

