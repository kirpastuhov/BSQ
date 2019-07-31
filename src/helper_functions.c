/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:11:46 by moverton          #+#    #+#             */
/*   Updated: 2019/07/30 18:12:23 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		ft_atoi(char *str)
{
	int num;
	int sign;

	num = 0;
	sign = 1;
	while (*str <= 32 || *str == 127)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -sign;
			str++;
		}
		else
			str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (num * sign);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
