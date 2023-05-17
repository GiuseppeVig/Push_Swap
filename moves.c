/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:45 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/16 14:28:13 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

static void swap(i_list **head)
{
	i_list	*temp;

	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = (*head);
	(*head) = temp;
}

static void rotate(i_list **head)
{
	i_list	*last;
	i_list	*first;

	last = ft_lstlast(*head);
	first = *head;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

static void reverse_rotate(i_list **head)
{
    i_list *tail = ft_lstlast(*head);
    i_list *pen = *head;

	while (pen->next->next != NULL)
	{
		pen = pen->next;
	}
    pen->next = NULL;
    tail->next = *head;
    *head = tail;
}

static void push(i_list **from, i_list **to)
{
	i_list *temp;

	if (!from)
		return ;
	temp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, temp);
	*to = temp;
}

static void printlist(i_list *head)
{
	while (head != NULL)
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
}
