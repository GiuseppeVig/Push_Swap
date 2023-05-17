/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:25:48 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/16 17:38:54 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct	list
{
	int	value;
	int	index;
	struct list	*next;
}				i_list;

int		ft_lstsize(i_list *lst);
void	ft_lstadd_front(i_list **lst, i_list *new);
void	ft_lstadd_back(i_list **lst, i_list *new);
i_list	*ft_lstnew(int n);
i_list	*ft_lstlast(i_list *lst);
i_list	*newlists(char **arguments, int n_args);
int		ordered(i_list *list);
int		choose_method(i_list *stack);
void	order(i_list *stack_a, i_list *stack_b);

#endif
