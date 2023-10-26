/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:15:29 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/28 16:34:15 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_stack **sa)
{
	if (rotate(sa) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **sb)
{
	if (rotate(sb) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **sa, t_stack **sb)
{
	if ((ft_lstsize(*sa) < 2) || (ft_lstsize(*sb) < 2))
		return (-1);
	rotate(sa);
	rotate(sb);
	write(1, "rr\n", 3);
	return (0);
}
