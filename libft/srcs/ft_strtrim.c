/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:54:07 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/25 13:45:07 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*c;
	const char	*k;

	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	k = s1 + ft_strlen(s1);
	while (ft_strchr(set, *k))
		k--;
	c = malloc(k - s1 + 2);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, k - s1 + 2);
	return ((char *)c);
}
