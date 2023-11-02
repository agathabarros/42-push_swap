/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:23:15 by agathabarro       #+#    #+#             */
/*   Updated: 2023/11/01 13:50:10 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Find the maximum value in the stack.
static int	max_value(t_stack **stack)
{
	t_stack	*top;
	int		max;
	int		max_bits;

	top = *stack;
	max = top->index;
	max_bits = 0;
	while (top)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
/*
radix_sort is a non-comparison sorting algorithm that sorts integers by grouping
them by individual digits that share the same significant position and value.
It sorts the stack by grouping the numbers by their least significant bit (LSB)
and then by their second least significant bit and so on until the most
significant bit (MSB) is reached.

*/

void	radix_sort(t_stack **sa, t_stack **sb)
{
	t_stack	*top_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	top_a = *sa;
	size = ft_lstsize(top_a);
	max_bits = max_value(sa);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *sa;
			// If the bit at position i is 1, rotate the stack a. 
			// Otherwise, push the number to stack b. 
			if (((top_a -> index >> i) & 1) == 1)
				ra(sa);
			else
				pb(sa, sb);
		}
		// Push the numbers from stack b to stack a.
		// Repeat the process until the most significant bit is reached.
		while (ft_lstsize(*sb) != 0)
			pa(sa, sb);
		i++;
	}
}
