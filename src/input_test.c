/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/30 20:19:10 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		g_strt;
int		g_rows;
char	g_spce;
char	g_obst;
char	g_sqre;

void	get_config(char *input)
{
	int i;
	int j;
	char *rows;

	i = 0;
	j = 0;
	while (input[i] != '\n')
		i++;
	g_strt = i + 1;
	g_sqre = input[i - 1];
	g_obst = input[i - 2];
	g_spce = input[i - 3];
	i = i - 4;	
	rows = malloc(i + 1);
	while (j <= i)
	{
		rows[j] = input[j];
		j++;
	}
	rows[j] = '\0';
	g_rows = ft_atoi(rows);
	free(rows);
}

int		main(int argc, char **argv)
{	
	char *test_str = ft_read_file(argv[1]);
	get_config(test_str);
	int test[ft_strlen(test_str)];
	printf("strlen: %d\n", ft_strlen(test_str));
	printf("strlen - config: %d\n", ft_strlen(test_str) - g_strt);
	printf("map_start: %d | space: %c | obstacle: %c | square: %c\n", g_strt, g_spce, g_obst, g_sqre);
	int i = 0;
	int j = 0;
	int k = 0;
	int start = g_strt;
	int rows = g_rows;
	int	cols = (ft_strlen(test_str) - g_strt) / rows;
	printf("rows: %d | cols: %d\n", rows, cols);
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
			printf("%2c", test_str[start++]);
			j++;
		}
		printf("\n");
		i++;
	}

	/* i = 0; */
	/* j = 0; */
	/* while (test_str[i]) */
	/* { */
	/* 	diag = 0; */
	/* 	abov = 0; */
	/* 	left = 0; */
	/* 	if (j != 0) */
	/* 		abov = test[i - cols]; */
	/* 	if (!((i / (j + 1) % cols) == 0)) */
	/* 		left = test[i - 1]; */
	/* 	if (!((i / (j + 1) % cols) == 0) && j != 0) */
	/* 		diag = test[i - cols - 1]; */
	/* 	if (test_str[i] == 'o') */
	/* 		test[i] = 0; */
	/* 	else */
	/* 	{ */
	/* 		test[i] = MIN3(left, abov, diag) + 1; */
	/* 		if (test[i] > size) */
	/* 		{ */
	/* 			size = test[i]; */
	/* 			position = i; */
	/* 		} */
	/* 	} */
	/* 	if ((i / (j + 1) % cols) == 0 && i != 0) */
	/* 		j++; */
	/* 	i++; */
	/* } */

	/* i = 0; */
	/* j = 0; */
	/* k = 0; */
	/* while (i < rows) */
	/* { */
	/* 	j = 0; */
	/* 	while (j < cols) */
	/* 	{ */
	/* 		printf("%3d", test[k++]); */
	/* 		j++; */
	/* 	} */
	/* 	printf("\n"); */
	/* 	i++; */
	/* } */
	/* col_counter = size; */
	/* row_counter = size; */
	/* printf("position: %d, size: %d\n", position, size); */
	/* while (row_counter > 0) */
	/* { */
	/* 	/1* printf("position: %d, rowcount: %d\n", position, row_counter); *1/ */
	/* 	while (col_counter > 0) */
	/* 	{ */
	/* 		/1* printf("position: %d, colcount: %d\n", position, col_counter); *1/ */
	/* 		test_str[position] = 'x'; */
	/* 		position--; */
	/* 		col_counter--; */
	/* 	} */
	/* 	col_counter = size; */
	/* 	row_counter--; */
	/* 	position = (position + size) - cols; */
	/* } */

	/* i = 0; */
	/* j = 0; */
	/* k = 0; */
	/* while (i < rows) */
	/* { */
	/* 	j = 0; */
	/* 	while (j < cols) */
	/* 	{ */
	/* 		printf("%3c", test_str[k++]); */
	/* 		j++; */
	/* 	} */
	/* 	printf("\n"); */
	/* 	i++; */
	/* } */
	return (0);
}
