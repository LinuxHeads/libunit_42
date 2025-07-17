/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:53:46 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/11 11:03:01 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ddest;
	unsigned char	*ssrc;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (ddest == NULL && ssrc == NULL)
		return (NULL);
	while (n--)
	{
		*ddest++ = *ssrc++;
	}
	return (dest);
}
