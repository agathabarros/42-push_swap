/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:52:41 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/29 09:51:10 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
 * Returns the last element of the list. 
 */
t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*last;

	last = head;
	while (last->next)
	{
		last = last->next;
		if (last->next == NULL)
			return (last);
	}
	return (last);
}
