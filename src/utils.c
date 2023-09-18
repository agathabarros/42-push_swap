/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:32:49 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/17 14:47:57 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ft_putstr(char *str)
{
    while(*str)
    {
        write(1, &str, 1);
        str++;
    }
}

void free_stack(t_stack **lst)
{
    t_stack *tmp;

    if(!lst || !*lst)
        return ;
    while(*lst)
    {
        tmp = (*lst)->next;
        free(*lst);
        *lst = tmp;
    }
    *lst = NULL;
}

long int ft_atoi(const char *s)
{
    long int n;
    int sign;

    n = 0;
    sign = 1;
    while(*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    while(*s == '-' || *s == '+')
    {
        if(*s == '-')
            sign *= -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        n = n * 10 + (*s - '0');
        s++;
    }
    return (n * sign);
}