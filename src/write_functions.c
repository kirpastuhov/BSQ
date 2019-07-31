/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:28:38 by moverton          #+#    #+#             */
/*   Updated: 2019/07/31 12:08:09 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/*
** ┌────────────────────────────────────────────────┐
** │     measure the length and check characters    │
** └────────────────────────────────────────────────┘
*/

int		ft_strlen_check(char *str, char space, char obs, int rows)
{
	int counter;

	counter = 0;
	while (*str)
	{
		if (!(*str == space || *str == obs))
			return (-1);
		str++;
		counter++;
	}
	if (counter % rows != 0)
		return (-1);
	else
		return (counter);
}

/*
** ┌────────────────────────────────────────────────┐
** │            measure the length                  │
** └────────────────────────────────────────────────┘
*/

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		str++;
		counter++;
	}
	return (counter);
}

/*
** ┌────────────────────────────────────────────────┐
** │     print string to given output stream        │
** └────────────────────────────────────────────────┘
*/

void	ft_putstr(char *str, int output)
{
	if (output == 1)
		write(1, str, ft_strlen(str));
	else
		write(2, str, ft_strlen(str));
}

/*
** ┌────────────────────────────────────────────────┐
** │     print number to standart output            │
** └────────────────────────────────────────────────┘
*/

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", 1);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

/*
** ┌────────────────────────────────────────────────┐
** │     compare strings by ascii values            │
** └────────────────────────────────────────────────┘
*/

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!(s1[i] == s2[i]))
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
