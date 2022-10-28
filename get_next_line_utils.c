/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:31:54 by aybiouss          #+#    #+#             */
/*   Updated: 2022/10/28 13:34:19 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(len - start + 1);
	if (!mem)
		return (NULL);
	while (len > start)
		mem[i++] = s[start++];
	mem[i] = '\0';
	return (mem);
}

char	*ft_strcat(char *dest, char *source)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while(source[i])
		dest[len++] = source[i++];
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s;
	int		len1;

	i = 0;
	len1 = ft_strlen(s1);
	s = malloc(len1 + ft_strlen(s2));
	if (!s)
		return (NULL);
	s = ft_strcat(s1, s2);
	return (S);
}

char	*ft_strdup(char *str)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc(ft_strlen(str) + 1);
	if (!mem)
		return (NULL);
	while (str[i])
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
