/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:28:49 by kpastukh          #+#    #+#             */
/*   Updated: 2019/07/29 15:40:21 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFFER_SIZE 4096
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

void	ft_putchar(char c);
void	ft_putstr(char *str, int output);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int		ft_error(char *arg, int nbr);
int		ft_getchar(char c);
void	ft_get_input(void);
char	*ft_read_file(char *filename);

#endif
