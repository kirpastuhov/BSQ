/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/31 20:42:58 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		g_strt;
int		g_rows;
char	g_spce;
char	g_obst;
char	g_sqre;
int		g_size;
int		g_posn;
int		g_abov;
int		g_left;
int 	g_diag;
int		g_i;
int		g_j;

void	get_config(char *input)
{
	char *rows;

	g_i = 0;
	g_j = 0;
	while (input[g_i] != '\n')
		g_i++;
	g_strt = g_i + 1;
	g_sqre = input[g_i - 1];
	g_obst = input[g_i - 2];
	g_spce = input[g_i - 3];
	g_i = g_i - 4;	
	rows = malloc(g_i + 1);
	while (g_j <= g_i)
	{
		rows[g_j] = input[g_j];
		g_j++;
	}
	rows[g_j] = '\0';
	g_rows = ft_atoi(rows);
	free(rows);
}

int		main(int argc, char **argv)
{
	char *test_str = ft_read_file(argv[1]);
	get_config(test_str);
	int test[ft_strlen(test_str) - g_strt - g_rows];

	printf("strlen: %d\n", ft_strlen(test_str));
	printf("strlen - config: %d\n", ft_strlen(test_str) - g_strt);
	printf("map_start: %d | space: %c | obstacle: %c | square: %c\n", g_strt, g_spce, g_obst, g_sqre);
	g_i = 0;
	g_j = 0;
	int start = g_strt;
	int rows = g_rows;
	int	cols = (ft_strlen(test_str) - g_strt - g_rows) / rows;
	printf("rows: %d | cols: %d\n", rows, cols);
	g_size = 0;
	g_posn = 0;
	int col_counter;
	int row_counter;

	ft_putstr(test_str, 1);
	write(1, "\n", 1);

	g_i = 0;
	g_j = 0;
	start = g_strt;
	ft_fill_intarr(test_str, test, g_strt, cols);

	col_counter = g_size;
	row_counter = g_size;
	printf("g_posn: %d, g_size: %d\n", g_posn, g_size);
	ft_fill_spaces(test_str, g_size, g_size, cols);
	ft_putstr(test_str, 1);
	write(1, "\n", 1);
	return (0);
}

void	ft_fill_intarr(char *str, int arr[], int start, int cols)
{
	while (str[start])
	{
		ft_zero_vars3(&g_abov, &g_diag, &g_left);
		if (str[start] == '\n')
			start++;
		if (g_j != 0)
			g_abov = arr[g_i - cols];
		if (!((g_i / (g_j + 1) % cols) == 0))
			g_left = arr[g_i - 1];
		if (!((g_i / (g_j + 1) % cols) == 0) && g_j != 0)
			g_diag = arr[g_i - cols - 1];
		if (str[start] == 'o')
			arr[g_i] = 0;
		else
		{
			arr[g_i] = MIN3(g_left, g_abov, g_diag) + 1;
			if (arr[g_i] > g_size)
			{
				g_size = arr[g_i];
				g_posn = start;
			}
		}
		if ((g_i / (g_j + 1) % cols) == 0 && g_i != 0)
			g_j++;
		g_i++;
		start++;
	}
}


void	ft_fill_spaces(char *str, int col_counter, int row_counter, int cols)
{
	while (row_counter > 0)
	{
		while (col_counter > 0)
		{
			str[g_posn] = 'x';
			g_posn--;
			col_counter--;
		}
		col_counter = g_size;
		row_counter--;
		g_posn = (g_posn + g_size - 1) - cols;
	}
}


