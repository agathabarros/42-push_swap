/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:01:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/28 16:12:02 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	main_index(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	int		i;

	i = 0;
	if (ac == 2)
	{
		while (*av[i])
		{
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(stack, new);
			i++;
		}
	}
}

/*static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}*/

int	main(int ac, char **av)
{
	t_stack	**sa;
	t_stack	**sb;

	if (ac < 2)
		return (-1);
	checks_args(ac, av);
	sa = (t_stack **)malloc(sizeof(t_stack));
	*sa = NULL;
	main_index(sa, ac, av);
	if (is_sorted(sa) == 1)
		exit (EXIT_SUCCESS);
	sb = (t_stack **)malloc(sizeof(t_stack));
	*sb = NULL;
	//sort_stack(stack_a, stack_b);
	free_stack(sa);
	free_stack(sb);
	return (0);
}
