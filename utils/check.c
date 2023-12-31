/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:57:20 by agathabarro       #+#    #+#             */
/*   Updated: 2023/11/01 13:21:38 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
* 
*/
static int	contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (num == ft_atoi(av[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
* checks if the string is a integer number.
*/

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	checks_args(int ac, char **av)
{
	long	i;
	long	tmp;

	i = 1;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (!ft_isnum(av[i]))
			error("Error");
		if (contains(tmp, av, i) == 1)
			error("Error");
		if (tmp > INT_MAX || tmp < INT_MIN)
			error("Error");
		i++;
	}
	if (ac == 2)
		free_string(av);
}

/*
* is_sorted() checks if the stack is sorted. 
*/
int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		// this condtion checks if the stack is sorted in ascending order.
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	// if the stack is sorted in ascending order, it returns 1.
	return (1);
}
