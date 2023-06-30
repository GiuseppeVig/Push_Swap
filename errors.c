/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:22:11 by gvigilan          #+#    #+#             */
/*   Updated: 2023/06/30 11:27:26 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(int n, t_stack *values)
{
	t_stack *head;

	head = values;
	while (head != NULL)
	{
		if (head->value == n)
			return (1);
		head = head->next;
	}
	return (0);
}

int	is_valid_num(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_space(t_stack *head)
{
	t_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->next = NULL;
		free(tmp);
	}
}
