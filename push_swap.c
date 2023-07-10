/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/10 12:54:39 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_list(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head != NULL)
	{
		ft_printf("Value: %d, Index: %d\n", head->value, head->index);
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		insert_values(&a, argv);
	else if (argc > 2)
		a = newstack(argv, argc);
	b = NULL;
	if (ft_stacksize(a) == 1)
		return (0);
	if (!ordered(a))
	{
		initial_push(&a, &b);
		assign_positions(a);
		assign_positions(b);
		order_stacks(&a, &b);
	}
	free_space(a);
	free_space(b);
	return (0);
}
