/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:01:21 by agathabarro       #+#    #+#             */
/*   Updated: 2023/11/01 18:13:37 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"



static void	init_stack(t_stack **stack, char **av)
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
}
// sort_stack() is the main function of the program. It sorts the stack.
// If the stack has 5 or less elements, it uses simple_sort().
// Otherwise, it uses radix_sort().
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
/*
* 
* 1. Checks if the arguments are valid
* 2. Initializes the stack
* 3. Sorts the stack
* 4. Frees the stack
* 5. Exits		
*/

int	main(int ac, char **av)
{
	t_stack	**sa;
	t_stack	**sb;

	if (ac <= 2)
		checks_args(ac, av);
	return (-1);
	checks_args(ac, av);
	sa = (t_stack **)malloc(sizeof(t_stack));
	*sa = NULL;
	init_stack(sa, av);
	// if the stack is already sorted, there is no need to sort it.
	if (is_sorted(sa) == 1)
	{
		free_stack(sa);
		exit (EXIT_SUCCESS);
	}
	sb = (t_stack **)malloc(sizeof(t_stack));
	*sb = NULL;
	sort_stack(sa, sb);
	free_stack(sa);
	free_stack(sb);
	return (0);
}
