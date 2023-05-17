/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:31:27 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/16 14:29:35 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"

i_list	*newlists(char **arguments, int n_args)
{
	i_list	*newlist;
	i_list	*newnode;
	int		n;

	n = 1;
	newlist = ft_lstnew(ft_atoi(arguments[n]));
	n ++;
	while (n < n_args)
	{
		newnode = ft_lstnew(ft_atoi(arguments[n]));
		ft_lstadd_back(&newlist, newnode);
		n++;
	}
	return (newlist);
}

int	ordered(i_list *list)
{
	while (list != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	choose_method(i_list *stack)
{
	int	len;
	int	pos;

	len = ft_lstsize(stack);
	pos = 0;
	while (stack != NULL)
	{
		if (stack->next->value < stack->value)
		{
			if (pos == 0)
				return (1);
			else if (pos < len/2)
				return (2);
			else if (pos > len/2)
				return (3);
		}
		pos++;
		stack = stack->next;
	}
	return (0);
}

static void order(i_list *stack_a, i_list *stack_b)
{
	while (!ordered(stack_a))
	{
		if (choose_method(stack_a) == 1)
			{
				swap(&stack_a);
				ft_printf("sa");
			}
		if (choose_method(stack_a) == 2)
			{
				rotate(&stack_a);
				ft_printf("ra");
			}
		if (choose_method(stack_a) == 3)
			{
				reverse_rotate(&stack_a);
				ft_printf("rra");
			}
		if (choose_method(stack_a) == 4)
			{
				push(&stack_a, &stack_b);
				ft_printf("pb");
			}
	}
}
