/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:47:52 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/10 18:07:44 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	i = 0;
	if (!s)
		return (NULL);
	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, (char)s[i]);
		if (!c[i])
			return (NULL);
		i++;
	}
	c[i] = '\0';
	return (c);
}
