/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:28:49 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/31 20:24:55 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFFER_SIZE 131072

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))
# define MIN(x, y) ((x < y) ? (x) : (y))
# define MIN3(x, y, z) ((MIN(x, y) < z) ? (MIN(x, y)) : (z))

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>

void	ft_putchar(char c);
void	ft_putstr(char *str, int output);
void	ft_putnbr(int nb);
int		ft_strlen_check(char *str, char space, char obs, int rows);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int		ft_validate(char *str, int rows, int cols);
int		ft_error(int nbr);
int		ft_getchar(char c);
void	ft_get_input(void);
char	*ft_read_file(char *filename);
void	ft_zero_vars2(int *i, int *j);
void	ft_zero_vars3(int *i, int *j, int *k);
void	ft_fill_spaces(char *str, int col_counter, int row_counter, int cols);

int		ft_atoi(char *str);

#endif
