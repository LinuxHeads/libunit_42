/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:43:30 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/06 16:34:15 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (ft_strchr(s, c) != NULL)
			a = ft_strchr(s, c);
		s++;
	}
	if ((char)c == '\0')
		a = (char *)s;
	return (a);
}
