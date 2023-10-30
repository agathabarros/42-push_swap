/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:23:15 by agathabarro       #+#    #+#             */
/*   Updated: 2023/10/27 17:13:39 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
/**/

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
			if (((top_a -> index >> i) & 1) == 1)
				ra(sa);
			else
				pb(sa, sb);
		}
		while (ft_lstsize(*sb) != 0)
			pa(sa, sb);
		i++;
	}
}
