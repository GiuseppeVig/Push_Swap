/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:25:48 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/25 14:53:15 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct	s_stack
{
	int	value;
	int	index;
	struct list	*next;
}				t_stack;

int		ft_stacksize(t_stack *lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int n);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*newstack(char **arguments, int n_args);
int		ordered(t_stack *list);
int		choose_method(t_stack *stack);
void	order(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	push(t_stack **from, t_stack **to);
void	printlist(t_stack *head);
int		find_next_min(t_stack *stack);
int		find_next_max(t_stack *stack);
void	assign_positions(t_stack *stack);
void	initial_push(t_stack **stack_a, t_stack **stack_b);
int		ordered(t_stack *stack);

#endif
