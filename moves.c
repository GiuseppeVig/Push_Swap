/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:45 by gvigilan          #+#    #+#             */
/*   Updated: 2023/06/30 22:36:31 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

void	swap(t_stack **head, int i)
{
	t_stack	*temp;

	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = (*head);
	(*head) = temp;
	if (i == 1)
		ft_printf("sa\n");
	else if (i == 2)
		ft_printf("sb\n");
}

void	rotate(t_stack **head, int i)
{
	t_stack	*last;
	t_stack	*first;

	last = ft_stacklast(*head);
	first = *head;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	if (i == 1)
		ft_printf("ra\n");
	else if (i == 2)
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **head, int i)
{
    t_stack *tail = ft_stacklast(*head);
    t_stack *pen = *head;

	while (pen->next->next != NULL)
	{
		pen = pen->next;
	}
    pen->next = NULL;
    tail->next = *head;
    *head = tail;
	if (i == 1)
		ft_printf("rra\n");
	else if (i == 2)
		ft_printf("rrb\n");
}

void	push(t_stack **from, t_stack **to, int i)
{
	t_stack *temp;

	if (!from)
		return ;
	temp = *from;
	*from = (*from)->next;
	ft_stackadd_front(to, temp);
	*to = temp;
	if (i == 1)
		ft_printf("pb\n");
	else if (i == 2)
		ft_printf("pa\n");
}
