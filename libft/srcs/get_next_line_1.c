/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:40:55 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/12 17:28:30 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <string.h>

char	*remove_null_1(char *buf)
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

char	*put_null_1(char *buf)
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

char	*read_fun_1(int fd, char *buf)
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
	buf = put_null_1(buf);
	return (free(tmp), buf);
}

char	*get_next_line_1(int fd)
{
	static char	*buf = NULL;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (buf == NULL)
		buf = ft_strdup("");
	else if (ft_strchr(buf, '\n'))
	{
		buf = remove_null_1(buf);
		if (!buf)
			return (NULL);
		if (ft_strchr(buf, '\n'))
		{
			buf = put_null_1(buf);
			tmp = ft_strdup(buf);
			return (tmp);
		}
	}
	else
		return (free(buf), buf = NULL, buf);
	buf = read_fun_1(fd, buf);
	if (!buf)
		return (NULL);
	return (tmp = ft_strdup(buf), tmp);
}
