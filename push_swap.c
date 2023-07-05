/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/05 05:09:54 by gvigilan         ###   ########.fr       */
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
    t_stack *a;
    t_stack *b;

    a = NULL;
    if (argc == 2)
        insert_values(&a, argv);
    else if (argc > 2)
        a = newstack(argv,argc);
    b = NULL;
    if (!ordered(a))
    {
        initial_push(&a, &b);
        order_stacks(&a, &b);
    }
    free_space(a);
    free_space(b);
}
