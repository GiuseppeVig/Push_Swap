/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:06:18 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/24 17:44:41 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		i ++;
		lst = lst->next;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_stacklast(*lst);
	temp->next = new;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = (*lst);
	(*lst) = new;
}

t_stack	*ft_stacknew(int n)
{
	t_stack			*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (0);
	newnode->value = n;
	newnode->index = -1;
	newnode->next = 0;
	return (newnode);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst ->next;
	return (lst);
}
