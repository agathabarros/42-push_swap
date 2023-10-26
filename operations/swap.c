/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:15:31 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/28 16:35:34 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		t_val;
	int		t_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error("Error");
	t_val = head->value;
	t_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = t_val;
	next->index = t_index;
	return (0);
}

int	sa(t_stack **sa)
{
	if (swap(sa) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **sb)
{
	if (swap(sb) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack **sa, t_stack **sb)
{
	if ((ft_lstsize(*sa) < 2) || (ft_lstsize(*sb) < 2))
		return (-1);
	swap(sa);
	swap(sb);
	write(1, "ss\n", 3);
	return (0);
}
