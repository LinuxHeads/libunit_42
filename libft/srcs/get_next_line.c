/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:40:55 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/12 17:29:34 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <string.h>

char	*remove_null(char *buf)
{
	char	*tmp;

	if (*buf == '\0')
		return (buf);
	tmp = ft_strdup(buf + ft_strlen(buf) + 1);
	if (!tmp)
		return (free(buf), NULL);
	free(buf);
	return (tmp);
}

char	*put_null(char *buf)
{
	int		i;
	int		j;
	int		found_newline;
	char	*buf1;

	i = 0;
	j = 0;
	found_newline = 0;
	if (!ft_strchr(buf, '\n'))
		return (buf);
	buf1 = malloc(ft_strlen(buf) + 2);
	if (!buf1)
		return (NULL);
	while (buf[i] != '\0')
	{
		buf1[j++] = buf[i];
		if (buf[i++] == '\n' && !found_newline)
		{
			found_newline = 1;
			buf1[j++] = '\0';
		}
	}
	buf1[j] = '\0';
	return (free(buf), buf1);
}

char	*read_fun(int fd, char *buf)
{
	char	*tmp;
	int		noc;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (1)
	{
		noc = read(fd, tmp, BUFFER_SIZE);
		if (noc == -1)
			return (free(buf), free(tmp), NULL);
		tmp[noc] = '\0';
		if (noc == 0 && *tmp == '\0' && *buf == '\0')
			return (free(buf), free(tmp), NULL);
		buf = ft_strjoin(buf, tmp, 0);
		if (!buf)
			return (NULL);
		if (noc < BUFFER_SIZE || ft_strchr((char *)tmp, '\n'))
			break ;
	}
	buf = put_null(buf);
	return (free(tmp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (buf == NULL)
		buf = ft_strdup((char *)"");
	else if (ft_strchr(buf, '\n'))
	{
		buf = remove_null(buf);
		if (!buf)
			return (NULL);
		if (ft_strchr(buf, '\n'))
		{
			buf = put_null(buf);
			if (!buf)
				return (NULL);
			return ((char *)buf);
		}
	}
	else
		return (free(buf), NULL);
	buf = read_fun(fd, buf);
	if (!buf)
		return (NULL);
	return ((char *)buf);
}
