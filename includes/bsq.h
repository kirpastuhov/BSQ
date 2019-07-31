/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:28:49 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/30 20:27:08 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFFER_SIZE 4096

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

int		ft_atoi(char *str);

#endif
