/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/30 20:19:10 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		main(void)
{
	char 	test_str[] = "...............................o..................................o.............................................o.....................................o............................................o..............o.......o.......o................";

	int 	test[ft_strlen(test_str)];
	int 	i = 0;
	int 	j = 0;
	int 	k = 0;
	int		rows = 9;
	int 	len = ft_strlen_check(test_str, '.', 'o', rows);
	int		cols = len / rows;
	if (len == -1)
		ft_error(len);
	else
		printf("valid map");
	int diag;
	int abov;
	int left;
	int	size;
	int position;
	int col_counter;
	int row_counter;

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
			test[i] = 0;
		else
		{
			test[i] = MIN3(left, abov, diag) + 1;
			if (test[i] > size)
			{
				size = test[i];
				position = i;
			}
		}
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
	col_counter = size;
	row_counter = size;
	printf("position: %d, size: %d\n", position, size);
	while (row_counter > 0)
	{
		/* printf("position: %d, rowcount: %d\n", position, row_counter); */
		while (col_counter > 0)
		{
			/* printf("position: %d, colcount: %d\n", position, col_counter); */
			test_str[position] = 'x';
			position--;
			col_counter--;
		}
		col_counter = size;
		row_counter--;
		position = (position + size) - cols;
	}

	i = 0;
	j = 0;
	k = 0;
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
	return (0);
}
