/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:31:20 by aybiouss          #+#    #+#             */
/*   Updated: 2022/10/28 20:23:21 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*all;
	char		*line;
	int			length;
	int			newline;

	line = NULL;
	if (!all)
		return (ft_strdup(""));
	length = read(fd, buf, BUFFER_SIZE);
	while (length >= 0)
	{
		buf[length] = 0;
		all = ft_strjoin(all, buf);
		newline = check_newline(all);
		if (newline)
			return (returned_line(line, all, newline));
		if (!length && !all[0])
			break ;
		if (!length)
			return (kept_one(all));
		length = read(fd, buf, BUFFER_SIZE);
	}
	free(all);
	all = NULL;
	return (NULL);
}

char	*kept_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*returned_line(char *line, char *all, int newline)
{
	line = ft_substr(all, 0, newline + 1);
	all = kept_one(all);
	return (line);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
