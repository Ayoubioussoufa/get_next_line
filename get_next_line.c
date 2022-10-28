/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:31:20 by aybiouss          #+#    #+#             */
/*   Updated: 2022/10/28 13:58:03 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*all;
	char		*line;
	int			i;
	int			length;
	int			newline;

	if (!all)
		return (ft_strdup(""));
	length = read(fd, buf, BUFFER_SIZE);
	while (length >= 0)
	{
		buf[length] = 0;
		all = ft_strjoin(all, buf);
		newline = check_newline(all);
		if (newline)
			return (returnedline(line, all, newline + 1));
		if (!length && !all[0])
			break ;
		if (!length)
			return (checker());
		length = read(fd, buf, BUFFER_SIZE);
	}
	free(all);
	all = NULL;
	return (NULL);
}

char	*returnedline(char *line, char *str, int newline)
{
	line = ft_substr(str, 0, newline);
	return (line);
}

char	*checker(char *all, char *line)
{
	line = 
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
