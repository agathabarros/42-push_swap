/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:15:26 by agathabarro       #+#    #+#             */
/*   Updated: 2023/11/01 13:50:27 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// reverse the stack
// the last element becomes the first
static int	reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(*stack);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **sa)
{
	if (reverse(sa) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **sb)
{
	if (reverse(sb) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **sa, t_stack **sb)
{
	if ((ft_lstsize(*sa) < 2) || (ft_lstsize(*sb) < 2))
		return (-1);
	reverse(sa);
	reverse(sb);
	write(1, "rrr\n", 4);
	return (0);
}
