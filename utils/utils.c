/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:32:49 by agathabarro       #+#    #+#             */
/*   Updated: 2023/10/30 14:04:22 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**/

void	free_stack(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*top;

	top = *lst;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(lst);
}

int	distance_to_top(t_stack **stack, int index)
{
	t_stack	*top;
	int		distance;

	top = *stack;
	distance = 0;
	while (top)
	{
		if (top->index == index)
			break ;
		distance++;
		top = top->next;
	}
	return (distance);
}

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack		*top;
	t_stack		*min;
	int			has_min;

	min = NULL;
	has_min = 0;
	top = *stack;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!has_min || top->value < min->value))
			{
				min = top;
				has_min = 1;
			}
			top = top->next;
		}
	}
	return (min);
}

int	get_min(t_stack **stack, int size)
{
	t_stack		*top;
	int			min;

	top = *stack;
	min = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min) && top->index != size)
			min = top->index;
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*top;
	int		index;

	index = 0;
	top = get_next_min(stack);
	while (top)
	{
		top->index = index++;
		top = get_next_min(stack);
	}
}
