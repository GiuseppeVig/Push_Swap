/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:31:27 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/24 17:42:26 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"

t_stack	*newstack(char **arguments, int n_args)
{
	t_stack	*newlist;
	t_stack	*newnode;
	int		n;

	n = 1;
	newlist = ft_stacknew(ft_atoi(arguments[n]));
	n ++;
	while (n < n_args)
	{
		newnode = ft_stacknew(ft_atoi(arguments[n]));
		ft_stackadd_back(&newlist, newnode);
		n++;
	}
	return (newlist);
}

int	choose_method(t_stack *stack)
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

static void order(t_stack *stack_a, t_stack *stack_b)
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
