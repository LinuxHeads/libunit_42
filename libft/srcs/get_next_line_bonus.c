/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:04:10 by malsharq          #+#    #+#             */
/*   Updated: 2024/10/17 17:16:37 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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
	if (!buf)
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

char	*get_next_line_bonus(int fd)
{
	static char	*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd] == NULL)
		buf[fd] = ft_strdup((char *)"");
	else if (ft_strchr(buf[fd], '\n'))
	{
		buf[fd] = remove_null(buf[fd]);
		if (!buf[fd])
			return (NULL);
		if (ft_strchr(buf[fd], '\n'))
		{
			buf[fd] = put_null(buf[fd]);
			if (!buf[fd])
				return (NULL);
			return ((char *)buf[fd]);
		}
	}
	else
		return (free(buf[fd]), NULL);
	buf[fd] = read_fun(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	return ((char *)buf[fd]);
}
