/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:51:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/27 17:01:27 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
 * Returns the number of elements in the list. 
 */

int	ft_lstsize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
