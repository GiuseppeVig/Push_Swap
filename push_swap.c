/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/05/16 14:28:25 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

extern i_list	*newlists(char **arguments, int n_args);
extern void printlist(i_list *head);

int main(int argc, char** argv)
{
    printf("par:%d prog:%s\n",argc,argv[0]);
    i_list *list=newlists(argv,argc);
    printlist(list);


}
