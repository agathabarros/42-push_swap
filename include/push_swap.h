/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:05:10 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/28 16:04:07 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>// WRITE
# include <stdlib.h>// MALLOC
# include <limits.h>// INT_MIN & INT_MAX

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

//**----------utils/utils----------**/
void		free_stack(t_stack **lst);
void		ft_putstr(char *str);

//**----------utils/check----------**/
void		checks_args(int ac, char **av);
int			is_sorted(t_stack **stack);

//**----------utils/erro----------**/
void		error(char *msg);
void		free_string(char **str);

//**----------operations----------**/
int			pa(t_stack **sa, t_stack **sb);
int			pb(t_stack **sa, t_stack **sb);
int			sa(t_stack **sa);
int			sb(t_stack **sb);
int			ss(t_stack **sa, t_stack **sb);
int			ra(t_stack **sa);
int			rb(t_stack **sb);
int			rr(t_stack **sa, t_stack **sb);
int			rra(t_stack **sa);
int			rrb(t_stack **sb);
int			rrr(t_stack **sa, t_stack **sb);
int			index_distance_head(t_stack **stack, int index);

//**----------lib_functions----------**/
size_t		ft_strlen(const char *str);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_lstsize(t_stack *head);
void		ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack		*ft_lstnew(int value);
t_stack		*ft_lstlast(t_stack *lst);

#endif