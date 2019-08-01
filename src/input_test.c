/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/31 21:31:34 by kpastukh         ###   ########.fr       */
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
int		g_diag;
int		g_i;
int		g_j;

void	get_config(char *input)
{
	char *rows;

	ft_zero_vars2(&g_i, &g_j);
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
	int		cols;
	char	*str;
	int		counter;

	counter = 0;
	while (++counter < argc)
	{
		str = ft_read_file(argv[counter]);
		get_config(str);
		ft_zero_vars2(&g_i, &g_j);
		cols = (ft_strlen(str) - g_strt - g_rows) / g_rows;
		ft_zero_vars2(&g_size, &g_posn);
		ft_fill_intarr(str, g_strt - 1, cols);
		ft_fill_spaces(str, g_size, g_size, cols);
		ft_putstr(str + g_strt, 1);
		if (!(counter + 1 == argc))
			write(1, "\n", 1);
	}
	return (0);
}

/*
** ┌────────────────────────────────────────────────┐
** │       fill in int array for algo               │
** └────────────────────────────────────────────────┘
*/

void	ft_fill_intarr(char *str, int start, int cols)
{
	int arr[ft_strlen(str) - g_strt - g_rows];

	while (str[++start])
	{
		ft_zero_vars3(&g_abov, &g_diag, &g_left);
		(str[start] == '\n') ? start++ : start;
		(g_j != 0) ? (g_abov = arr[g_i - cols]) : (g_abov);
		if (!((g_i / (g_j + 1) % cols) == 0))
			g_left = arr[g_i - 1];
		if (!((g_i / (g_j + 1) % cols) == 0) && g_j != 0)
			g_diag = arr[g_i - cols - 1];
		if (str[start] == g_obst)
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
		((g_i / (g_j + 1) % cols) == 0 && g_i != 0) ? g_j++ : g_j;
		g_i++;
	}
}

/*
** ┌────────────────────────────────────────────────┐
** │       mark biggest square on the map           │
** └────────────────────────────────────────────────┘
*/

void	ft_fill_spaces(char *str, int col_counter, int row_counter, int cols)
{
	while (row_counter > 0)
	{
		while (col_counter > 0)
		{
			str[g_posn] = g_sqre;
			g_posn--;
			col_counter--;
		}
		col_counter = g_size;
		row_counter--;
		g_posn = (g_posn + g_size - 1) - cols;
	}
}
