/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/01 00:38:23 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void    print_list(t_stack *stack)
{
    t_stack *head;

    head = stack;
    while (head != NULL)
    {
        ft_printf("Value: %d, Index: %d\n", head->value, head->index);
        head = head->next;
    }
}

int main(int argc, char** argv)
{
    t_stack *a = newstack(argv,argc);
    t_stack *b = NULL;
    if (!ordered(a))
    {
        initial_push(&a, &b);
        order_stacks(&a, &b);
    }
}
