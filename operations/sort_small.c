/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:07:56 by agathabarro       #+#    #+#             */
/*   Updated: 2023/11/01 17:36:10 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_132(t_stack **stack_a)
{
	ra (stack_a);
	sa (stack_a);
	rra (stack_a);
}

static void	sort_231(t_stack **stack_a, t_stack *top, int min)
{
	if (top->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_312(t_stack **stack_a, t_stack *top, int min)
{
	// if the top is the min, rotate
	if (top->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_3(t_stack **sa)
{
	t_stack	*top;
	int		min;
	int		next_min;

	top = *sa;
	min = get_min(sa, -1);
	next_min = get_min(sa, min);
	if (is_sorted(sa) == 1)
		return ;
	if (top->index == min && top->next->index != next_min)
		sort_132(sa);
	else if (top->index == next_min)
		sort_231(sa, top, min);
	else 
		sort_312(sa, top, min);
}
