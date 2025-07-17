/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:30:25 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/08 21:02:43 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <limits.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		len_little;
	const char	*start;

	len_little = ft_strlen(little);
	start = big;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (1)
	{
		big = (const char *)ft_strchr(big, *little);
		if (!big)
			break ;
		if ((big - start) + len_little > len)
			break ;
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
