/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:31:27 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/04 18:55:49 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"
#include "./ft_printf/libft/libft.h"

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
		if (compare(ft_atoi(arguments[n]), newlist) || !is_valid_num(arguments[n]))
		{
			write(2, "Error\n", 6);
			free_space(newlist);
			exit(1);
		}
		newnode = ft_stacknew(ft_atoi(arguments[n]));
		ft_stackadd_back(&newlist, newnode);
		n++;
	}
	return (newlist);
}

int	ordered(t_stack *a)
{
	t_stack *head = a;
	while (head->next != NULL)
	{
		if (head->next->value < head->value)
			return (0);
		head = head->next;
	}
	return (1);
}

t_stack *max_node(t_stack *st)
{
	t_stack *head;
	t_stack *max;

	head = st;
	max = st;
	while (head != NULL)
	{
		if (max->value < head->value)
			max = head;
		head = head->next;
	}
	return (max);
}

t_stack *min_node(t_stack *st)
{
	t_stack *head;
	t_stack *min;

	head = st;
	min = st;
	while (head != NULL)
	{
		if (min->value > head->value)
			min = head;
		head = head->next;
	}
	return (min);
}

void	insert_values(t_stack **new, char **values)
{
	int		i;
	t_stack	*tmp;
	t_stack	*head;
	char	**split;
	
	split = ft_split(values[1], ' ');
	i = 0;
	tmp = NULL;
	while (split[i] != NULL)
	{
		head = *new;
		if (compare(ft_atoi(split[i]), head) || !is_valid_num(split[i]))
		{
			write(2, "Error\n", 6);
			free_space(*new);
			exit(1);
		}
		tmp = ft_stacknew(ft_atoi(split[i]));
		ft_stackadd_back(new, tmp);
		i++;
	}
}