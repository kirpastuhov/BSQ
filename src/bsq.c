/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:27:39 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/29 16:03:16 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		main(int argc, char **argv)
{
	int		counter;
	char	*input;
	int		i;

	counter = 1;
	if (argc == 1)
		ft_get_input();
	while (counter < argc)
	{
		i = 0;
		input = ft_read_file(argv[counter]);
		while (input[i])
		{
			if (input[i] == '\n')
				i++;
			ft_putchar(input[i]);
			i++;
		}
		counter++;
	}
	return (0);
}
