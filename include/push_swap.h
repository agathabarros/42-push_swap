/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:05:10 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/17 15:26:00 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				main_index;
	int				position;
	int				where_fit;
	int				mv_b;
	int				mv_a;
	struct s_stack	*next;
}					t_stack;

//**----------create_stack----------**/
void main_index(t_stack *sa, int size);
t_stack		*creat_stack(int ac, char **av);
int size_stack(t_stack *st);

//**----------utils----------**/
void ft_putstr(char *str);
void free_stack(t_stack **lst);
long int ft_atoi(const char *s);

#endif