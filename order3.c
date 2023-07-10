/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:18:48 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/10 12:53:18 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_and_swap(t_stack **target)
{
	reverse_rotate(target, 1);
	swap(target, 1);
}

void	order_3(t_stack **a)
{
	t_stack	*head;

	while (!ordered(*a))
	{
		head = *a;
		assign_positions(head);
		if (find_next_min(head) == 0)
			rev_and_swap(a);
		else if (find_next_max(head) == 0)
		{
			rotate(a, 1);
			if (!ordered(*a))
				swap(a, 1);
		}
		else
		{
			if (find_next_max(head) == 1)
				reverse_rotate(a, 1);
			else
				swap(a, 1);
		}
	}
}
