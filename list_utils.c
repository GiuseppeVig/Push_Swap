/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:06:18 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/16 17:37:37 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(i_list *lst)
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

void	ft_lstadd_back(i_list **lst, i_list *new)
{
	i_list	*temp;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	ft_lstadd_front(i_list **lst, i_list *new)
{
	if (!new)
		return ;
	new->next = (*lst);
	(*lst) = new;
}

i_list	*ft_lstnew(int n)
{
	i_list			*newnode;

	newnode = (i_list *)malloc(sizeof(i_list));
	if (!newnode)
		return (0);
	newnode->value = n;
	newnode->index = -1;
	newnode->next = 0;
	return (newnode);
}

i_list	*ft_lstlast(i_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst ->next;
	return (lst);
}
