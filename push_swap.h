/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:25:48 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/04 18:51:26 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct	s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}				t_stack;

int		ft_stacksize(t_stack *lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int n);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*newstack(char **arguments, int n_args);
void	insert_values(t_stack **new, char **values);
int		ordered(t_stack *list);
void	swap(t_stack **head, int i);
void	rotate(t_stack **head, int i);
void	reverse_rotate(t_stack **head, int i);
void	push(t_stack **from, t_stack **to, int i);
void	swap_both(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b);
int		find_next_min(t_stack *stack);
int		find_next_max(t_stack *stack);
int		count_moves(t_stack *node, t_stack *a, t_stack *b);
void	assign_positions(t_stack *stack);
void	initial_push(t_stack **stack_a, t_stack **stack_b);
int		compare(int n, t_stack *values);
int		is_valid_num(char *c);
void	order_3(t_stack **a);
t_stack *max_node(t_stack *st);
t_stack *min_node(t_stack *st);
t_stack *search_next_node(t_stack *a, t_stack *b);
t_stack *choose_node(t_stack *b, t_stack *a);
t_stack	*next_node_a(t_stack *node, t_stack *a);
int		confront_moves(int max, int min, int node);
void	bring_node_on_top(t_stack **stack_b, t_stack *node);
void	move_stacks(t_stack **a, t_stack **b, t_stack *node);
void	order_stacks(t_stack **a, t_stack **b);
void	free_space(t_stack *head);
void    print_list(t_stack *stack);
void	adjust_stack_a(t_stack **a, t_stack *node);

#endif
