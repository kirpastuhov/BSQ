/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:11:10 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/29 21:38:53 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

# define ABS(Value) ((Value < 0) ? (-Value) : (Value))
# define MIN(x, y) ((x < y) ? (1) : (0))
# define MIN3(x, y) ((x< x-1))

int		main(void)
{
	char test_str[] = "...............................o..................................o.............................................o.....................................o............................................o..............o.......o.......o................";
	int test[ft_strlen(test_str)];
/*
** ┌────────────────────────────────────────────────┐
** │ test                                           │
** └────────────────────────────────────────────────┘
*/

	int i = 0;
	int j = 0;
	int rows = 9;
	int cols = ft_strlen(test_str) / rows;
	int diag;
	int abov;
	int left;

	for(int i = 0; i <= 8 ; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
			printf("%c", test_str[i]);
		}
		printf("\n");
	}

	/* while (test_str[i]) */
	/* { */
	/* 	diag = 0; */
	/* 	abov = 0; */
	/* 	left = 0; */
	/* 	if (!(i == 0)) */
	/* 		abov = test[i - cols]; */

	/* 	if (!(j == 0)) */
	/* 		left = test[i - 1]; */

	/* 	if (i != 0 && j != 0) */
	/* 		diag = test[i-cols - 1]; */

	/* 	if (test_str[i] == 'o') */
	/* 	{ */
	/* 		test[i] = left + abov - diag + 1; */
	/* 	} */
	/* 	else */
	/* 	{ */
	/* 		test[i] = left + abov - diag; */
	/* 	} */

	/* } */




	/* for(int i = 0; i <= 8 ; i++) */
	/* { */
	/* 	for (int j = 0; j <= 26; j++) */
	/* 	{ */
	/* 		printf("%d", test[i]); */
	/* 	} */
	/* 	printf("\n"); */
	/* } */

	/* /1* printf("\n%d < %d -> %d \n",k, 5, MIN(k,5)); *1/ */
	/* /1* printf("%d-len", ft_strlen(test_str)); *1/ */
	/* /1* printf("%d-len2", ft_strlen(ar[1])); *1/ */
	return (0);
}
