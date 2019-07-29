/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moverton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:39:56 by moverton          #+#    #+#             */
/*   Updated: 2019/07/29 16:09:24 by moverton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		ft_error(char *arg, int nbr)
{
	if (nbr == 1)
	{
		ft_putstr("ft_cat: ", 2);
		ft_putstr(arg, 2);
		ft_putstr(": No such file or directory\n", 2);
	}
	if (nbr == 2)
	{
		ft_putstr("ft_cat: ", 2);
		ft_putstr(arg, 2);
		ft_putstr(": Is a directory\n", 2);
	}
	return (1);
}

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

char	*ft_read_file(char *filename)
{
	int		fd;
	int		i;
	int		out;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	
	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(filename, 1);
		return (str);
	}
	out = read(fd, buffer, BUFFER_SIZE);
	if (errno == EISDIR)
	{
		ft_error(filename, 2);
		return (str);
	}
	buffer[out] = '\0';
	str = malloc(sizeof(char) * out);
	i = -1;
	while (buffer[++i])
		str[i] = buffer[i];
	str[i] = '\0';
	close(fd);
	return (str);
}
