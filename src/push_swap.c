/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:01:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/17 15:38:59 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int size;
    t_stack *sa;
    t_stack *sb;

    if(ac < 2)
        return (0);
    sa = creat_stack(ac, av);
    sb = NULL;
    size = size_stack(sa);
    main_index(sa, size);
    while(av)
    {
        printf("n = %d\n", sa->n);
        printf("main_index = %d\n", sa->main_index);
        sa = sa->next;
    }
    free_stack(&sa);
    free_stack(&sb);
}