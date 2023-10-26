/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:25 by agathabarro       #+#    #+#             */
/*   Updated: 2023/09/27 17:00:47 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Converts the initial portion of the string 
 * pointed to by str to int representation. 
 */
long	ft_atoi(const char *str)
{
	long	i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
