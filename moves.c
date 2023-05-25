/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:45 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/24 17:37:37 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

void	swap(t_stack **head)
{
	t_stack	*temp;

	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = (*head);
	(*head) = temp;
}

void	rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*first;

	last = ft_lstlast(*head);
	first = *head;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack **head)
{
    t_stack *tail = ft_lstlast(*head);
    t_stack *pen = *head;

	while (pen->next->next != NULL)
	{
		pen = pen->next;
	}
    pen->next = NULL;
    tail->next = *head;
    *head = tail;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack *temp;

	if (!from)
		return ;
	temp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, temp);
	*to = temp;
}

void	printlist(t_stack *head)
{
	while (head != NULL)
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
}
