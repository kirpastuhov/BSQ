/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:39:56 by moverton          #+#    #+#             */
/*   Updated: 2019/07/31 23:22:13 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int g_i;
int g_j;

/*
** ┌────────────────────────────────────────────────┐
** │              printing errors                   │
** └────────────────────────────────────────────────┘
*/

int		ft_error(int nbr)
{
	if (nbr == -1)
	{
		ft_putstr("map error\n", 2);
	}
	return (1);
}

/*
** ┌────────────────────────────────────────────────┐
** │           for handling errors                  │
** └────────────────────────────────────────────────┘
*/

int		ft_getchar(char c)
{
	if (c)
		return (1);
	return (-1);
}

char	*ft_get_input(void)
{
	int		i;
	int		j;
	int		out;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;

	out = read(0, buffer, BUFFER_SIZE);
	buffer[out] = '\0';
	str = malloc(sizeof(char) * out + 1);
	i = -1;
	j = 0;
	while (buffer[++i])
		str[i] = buffer[i];
	str[i] = '\0';
	return (str);
}

/*
** ┌────────────────────────────────────────────────┐
** │         read input from file                   │
** └────────────────────────────────────────────────┘
*/

char	*ft_read_file(char *filename)
{
	int		fd;
	int		out;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;

	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	out = read(fd, buffer, BUFFER_SIZE);
	buffer[out] = '\0';
	str = malloc(sizeof(char) * out + 1);
	g_i = -1;
	g_j = 0;
	while (buffer[++g_i])
		str[g_i] = buffer[g_i];
	str[g_i] = '\0';
	close(fd);
	return (str);
}
