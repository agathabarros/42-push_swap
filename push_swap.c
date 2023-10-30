/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:01:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/10/30 14:02:45 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	init_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	int		i;

	i = 1;
	while (av[i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		if (!new)
			exit (EXIT_FAILURE);
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (ac == 2)
	{
		free_string(av);
	}
	else 
	{
		free(av);
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	print_stack(t_stack *top)
{
	t_stack	*node;

	node = top;
	while (node != NULL)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	**sa;
	t_stack	**sb;

	if (ac < 2)
		return (-1);
	checks_args(ac, av);
	sa = (t_stack **)malloc(sizeof(t_stack));
	*sa = NULL;
	init_stack(sa, ac, av);
	if (is_sorted(sa) == 1)
		exit (EXIT_SUCCESS);
	sb = (t_stack **)malloc(sizeof(t_stack));
	*sb = NULL;
	sort_stack(sa, sb);
	//printf("Stack A: ");
	//print_stack(*sa);
	//printf("Stack B: ");
	//print_stack(*sb);
	free_stack(sa);
	free_stack(sb);
	return (0);
}
