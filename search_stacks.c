/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:25:05 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/10 12:55:11 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(t_stack *a)
{
	if (a->value < ft_stacklast(a)->value)
		return (1);
	return (0);
}

int	confront_moves(int max, int min, int node)
{
	if (node < min && node < max)
		return (node);
	else if (min < node && min < max)
		return (min);
	else
		return (max);
}

t_stack	*next_last_a(t_stack *node, t_stack *a)
{
	t_stack	*head;
	t_stack	*tmp;

	head = a;
	tmp = min_node(a);
	while (head->next != NULL)
	{
		if (node->value > head->value && head->value > tmp->value)
			tmp = head;
		head = head->next;
	}
	if (node->value > head->value && head->value > tmp->value)
		tmp = head;
	return (tmp);
}

t_stack	*search_next_node(t_stack *a, t_stack *b)
{
	t_stack	*head;
	t_stack	*next_node;

	head = b;
	next_node = b;
	while (head->next != NULL)
	{
		if (count_moves(head, a, b) < count_moves(next_node, a, b))
			next_node = head;
		head = head->next;
	}
	return (next_node);
}
