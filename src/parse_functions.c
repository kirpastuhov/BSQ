/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:39:56 by moverton          #+#    #+#             */
/*   Updated: 2019/07/31 12:10:00 by kpastukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/* TODO: refactor ft_read_file */

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
	if (nbr == 1)
	{
		ft_putstr("ft_cat: ", 2);
		ft_putstr(": No such file or directory\n", 2);
	}
	if (nbr == 2)
	{
		ft_putstr("ft_cat: ", 2);
		ft_putstr(": Is a directory\n", 2);
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

void	ft_get_input(void)
{
	int		flag;
	int		out;
	char	buffer[BUFFER_SIZE + 1];

	flag = 0;
	while (flag != -1)
	{
		out = read(0, buffer, 1);
		buffer[out] = '\0';
		ft_putstr(buffer, 1);
		flag = ft_getchar(buffer[0]);
	}
}

/*
** ┌────────────────────────────────────────────────┐
** │         read input from file                   │
** └────────────────────────────────────────────────┘
*/

char	*ft_read_file(char *filename)
{
	int		fd;
	int		i;
	int		j;
	int		out;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	int		newline;

	newline = 0;
	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	out = read(fd, buffer, BUFFER_SIZE);
	buffer[out] = '\0';
	str = malloc(sizeof(char) * out);
	i = -1;
	j = 0;
	while (buffer[++i])
	{
		if (newline == 0)
		{
			if (buffer[i] == '\n')
				newline++;
			str[j] = buffer[i];
		}
		else
		{
			if (buffer[i] == '\n')
				i++;
			str[j] = buffer[i];
		}
		j++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}
