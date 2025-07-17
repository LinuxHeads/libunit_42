/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:37:43 by malsharq          #+#    #+#             */
/*   Updated: 2024/10/31 19:20:34 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2, int flag)
{
	void	*a;

	if (!s1 || !s2)
		return (NULL);
	a = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	ft_strlcpy(a + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	if (flag == 1)
		free((char *)s2);
	free((char *)s1);
	return ((char *)a);
}
