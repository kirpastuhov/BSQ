/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:28:38 by moverton          #+#    #+#             */
/*   Updated: 2019/07/29 13:27:51 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putstr(char *str, int output)
{
	if (output == 1)
		write(1, str, ft_strlen(str));
	else
		write(2, str, ft_strlen(str));
}

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
