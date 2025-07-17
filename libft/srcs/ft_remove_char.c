/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:32:26 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/26 11:55:27 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_copy(char *str, char to_found, int count)
{
	int		i;
	int		j;
	char	*to_return;

	j = 0;
	i = 0;
	to_return = malloc(ft_strlen(str) - count + 1);
	if (!to_return)
		return (NULL);
	while (str[i])
	{
		if (str[i] != to_found)
			to_return[j++] = str[i];
		i++;
	}
	to_return[j] = '\0';
	return (to_return);
}

char	*ft_remove_char(char *str, char to_found)
{
	int		count;
	int		i;
	char	*to_return;

	i = 0;
	count = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i++] == to_found)
			count++;
	}
	to_return = ft_copy(str, to_found, count);
	free(str);
	return (to_return);
}
