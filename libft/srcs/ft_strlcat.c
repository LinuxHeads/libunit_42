/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:34:21 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/08 15:36:26 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	dstlen;
	size_t	srcllen;
	size_t	dst_size;

	dstlen = ft_strlen(dst);
	srcllen = ft_strlen(src);
	a = 0;
	dst_size = size - dstlen - 1;
	if (dstlen >= size)
		return (size + srcllen);
	else
	{
		while (dst_size-- && src[a] != '\0')
		{
			dst[a + dstlen] = src[a];
			a++;
		}
	}
	dst[dstlen + a] = '\0';
	return (srcllen + dstlen);
}
