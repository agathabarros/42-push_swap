/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:05:10 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/18 21:11:51 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // WRITE
# include <stdlib.h> // MALLOC
# include <limits.h> // INT_MIN & INT_MAX
# include <libft.h> // LIBFT FUNCTIONS

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;


//**----------src/create_stack----------**/
void main_index(t_stack *sa, int size);
t_stack		*creat_stack(int ac, char **av);
int size_stack(t_stack *st);

//**----------utils/utils----------**/
void ft_putstr(char *str);
void free_stack(t_stack **lst);
long int ft_atoi(const char *s);

//**----------utils/check----------**/
void checks_args(int ac, char **av);
int ft_isnum(char *num);
int contains(int num, char **av, int i);

//**----------utils/erro----------**/
void error(char *msg);
void free_string(char **str);


#endif