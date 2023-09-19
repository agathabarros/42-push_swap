/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:32:49 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/18 21:15:09 by agathabarro      ###   ########.fr       */
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
/*

*/
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

