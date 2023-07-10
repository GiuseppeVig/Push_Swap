/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:46:54 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/10 12:50:10 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_stack_a(t_stack **a, t_stack *node)
{
	t_stack	*tmp;

	tmp = next_last_a(node, *a);
	if (tmp->value == min_node(*a)->value && node->value < tmp->value)
	{
		bring_node_on_top(a, min_node(*a), 1);
		return ;
	}
	while (ft_stacklast(*a)->value != tmp->value)
	{
		if (ft_stacklast(*a)->value == tmp->value)
			break ;
		if (tmp->index < ft_stacksize(*a) / 2)
			rotate(a, 1);
		else
			reverse_rotate(a, 1);
	}
}

void	bring_node_on_top(t_stack **stack_b, t_stack *node, int i)
{
	t_stack	*head;

	head = *stack_b;
	while (head->value != node->value)
	{
		head = *stack_b;
		if (head->value == node->value)
			break ;
		if (node->index < ft_stacksize(*stack_b) / 2)
			rotate(stack_b, i);
		else
			reverse_rotate(stack_b, i);
		assign_positions(head);
	}
}

void	move_stacks(t_stack **a, t_stack **b, t_stack *node)
{
	t_stack	*last;
	t_stack	*chosen;

	last = ft_stacklast(*a);
	chosen = next_last_a(node, *a);
	while ((*b)->value != node->value)
	{
		while (last->value != chosen->value && (*b)->value != node->value)
		{
			if (node->index < ft_stacksize(*b) / 2)
				rotate_both(a, b);
			else
				reverse_rotate_both(a, b);
		}
		while (last->value != chosen->value && (*b)->value != node->value)
		{
			if (node->index > ft_stacksize(*b) / 2)
				rotate_both(a, b);
			else
				reverse_rotate_both(a, b);
		}
		bring_node_on_top(b, node, 2);
	}
}

void	order_stacks(t_stack **a, t_stack **b)
{
	t_stack	*next_node;

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
		if (min_node(*a)->index < ft_stacksize(*a) / 2)
			rotate(a, 1);
		else
			reverse_rotate(a, 1);
	}
}
