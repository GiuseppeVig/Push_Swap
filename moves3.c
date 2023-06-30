/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:48:10 by gvigilan          #+#    #+#             */
/*   Updated: 2023/06/30 16:31:46 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

void	swap_both(t_stack **a, t_stack **b)
{
	swap(b, 0);
	swap(a, 0);
	ft_printf("ss");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(b, 0);
	rotate(a, 0);
	ft_printf("rr");
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr");
}
