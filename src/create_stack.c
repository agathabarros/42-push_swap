/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:29:35 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/17 15:43:17 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void main_index(t_stack *sa, int size)
{
    t_stack *a;
    t_stack *max_adress;
    int max_n;

    while(size--)
    {
        a = sa;
        max_n = INT_MIN;
        max_adress = NULL;
        while(a)
        {
            if(a->n > max_n && a->main_index == 0)
                a->main_index = 1;
            else if (a->n > max_n && a->main_index == 0)
            {
                max_n = a->n;
                max_adress = a;
                a = sa;
            }
            else
                a = a->next;
        }
        if(max_adress)
            max_adress->main_index = size + 1;
    }
}
int size_stack(t_stack *st)
{
    int size;
    t_stack *tmp;
    
    size = 0;
    tmp = st;
    while(st)
    {
        size++;
        tmp = tmp->next;
    }
    return(size);
}
static t_stack *new_stack(long int n)
{
    t_stack *new;
    
    new = (t_stack *)malloc(sizeof(t_stack));
    if(!new)
        return (NULL);
    new->n = n;
    /*new->main_index = 0;
    new->position = -1;
    new->where_fit = -1;
    new->mv_a = -1;
    new-> mv_b = -1;*/
    new->next = NULL;
    return(new);
}
static void add_stack(t_stack **st, t_stack *new)
{
    t_stack *tmp;
    
    if (!new)    
        return ;
    if (!*st)
        *st = new;
    else
    {
        tmp = *st;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
t_stack *creat_stack(int ac, char **av)
{
    t_stack *sa;
    long int n;
    int i;

    sa = NULL;
    n = 0;
    i = 1;
    while(i < ac)
    {
        n = ft_atoi(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            return (NULL);
        if (i == 1)
            sa = new_stack((int)n);
        else
            add_stack(&sa, new_stack((int)n));
        i++;
    }
    return(sa);
}