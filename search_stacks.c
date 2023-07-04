/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:25:05 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/04 19:16:31 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	confront_moves(int max, int min, int node)
{
	if (node < min && node < max)
		return (node);
	else if (min < node && min < max)
		return (min);
	else
		return (max);
}

t_stack *choose_node(t_stack *b, t_stack *a)
{
	t_stack *head;
	int	i;
	int	maximum;
	int	minimum;

	head = a;
	i = count_moves(head, a, b);
	maximum = count_moves(max_node(b), a, b);
	minimum = count_moves(min_node(b), a, b);
	if (confront_moves(maximum, minimum, i) == maximum)
		return (max_node(b));
	else if (confront_moves(maximum, minimum, i) == i)
		return (head);
	else
		return (min_node(b));
}

t_stack	*next_node_a(t_stack *node, t_stack *a)
{
	t_stack *head;
	t_stack	*tmp;

	head = a;
	tmp = min_node(a);
/*	if (node->value < min_node(a)->value)
		return (min_node(a));
	if (node->value > max_node(a)->value)
		return (max_node(a));*/
//	else
//	{
		while (head->next != NULL)
		{
			if (node->value > head->value && head->value > tmp->value)
				tmp = head;
			head = head->next;
		}
		if (node->value > head->value && head->value > tmp->value)
			tmp = head;
		return (tmp);
//	}
}

t_stack *search_next_node(t_stack *a, t_stack *b)
{
	t_stack *head;
	t_stack	*next_node;

	head = b;
	next_node = b;
	while (count_moves(head, a, b) > count_moves(head, a, b) || head->next != NULL)
	{
		if (count_moves(next_node, a, b) < count_moves(head, a, b))
			next_node = head;
		head = head->next;
	}
	return (head);
}
