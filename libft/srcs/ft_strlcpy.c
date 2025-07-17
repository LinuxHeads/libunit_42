/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:56:47 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/13 17:29:46 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	t;

	t = 0;
	if (size)
	{
		if (size <= ft_strlen(src))
		{
			while (--size)
			{
				dst[t] = src[t];
				t++;
			}
			dst[t] = '\0';
		}
		else
		{
			while (src[t] != '\0')
			{
				dst[t] = src[t];
				t++;
			}
			dst[t] = '\0';
		}
	}
	return (ft_strlen(src));
}
