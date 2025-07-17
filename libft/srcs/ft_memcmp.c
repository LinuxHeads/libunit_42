/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:49:34 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/06 17:46:48 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				a;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	a = 0;
	while (n--)
	{
		if (*(s11 + a) != *(s22 + a))
			return (*(s11 + a) - *(s22 + a));
		a++;
	}
	return (0);
}
