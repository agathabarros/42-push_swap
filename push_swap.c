/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:01:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/18 21:12:30 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int void int_s(t_stack **stack, int ac, char **av)
{
    t_stack *new;
    char **args;
    int i;
    
    i = 0;
    while (args[i])
    {
        new = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(stack, new);
        i++;
    }
}
int main(int ac, char **av)
{
    int size;
    t_stack *sa;
    t_stack *sb;

    if(ac < 2)
        return (-1);
    checks_args(ac, av);
    sa = (t_stack *)malloc(sizeof(t_stack));
    sa = NULL;
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