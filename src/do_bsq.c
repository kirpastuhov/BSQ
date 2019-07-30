/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/29 23:54:03 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char *test_str = "...................o....................o...o.........o.................";
	int test[ft_strlen(test_str)];

	int i = 0;
	int j = 0;
	int k = 0;
	int rows = 6;
	int	cols = ft_strlen(test_str) / rows;
	int diag;
	int abov;
	int left;
	float mod;

	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%c", test_str[k++]);
			j++;
		}
		printf("\n");
		i++;
	}

	i = 0;
	j = 0;
	while (test_str[i])
	{
		diag = 0;
		abov = 0;
		left = 0;
		if (j != 0)
			abov = test[i - cols];
		if (!((i / (j + 1) % cols) == 0))
			left = test[i - 1];
		if (!((i / (j + 1) % cols) == 0) && j != 0)
			diag = test[i - cols - 1];
		if (test_str[i] == 'o')
			test[i] = left + abov - diag + 1;
		else
			test[i] = left + abov - diag;
		if ((i / (j + 1) % cols) == 0 && i != 0)
			j++;
		i++;
	}

	i = 0;
	j = 0;
	k = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d", test[k++]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
