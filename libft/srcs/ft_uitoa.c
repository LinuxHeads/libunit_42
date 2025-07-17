/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:26:29 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/21 20:07:19 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itoa2(int counter, char *c, unsigned int n)
{
	unsigned int	a;

	a = n;
	c[counter] = '\0';
	while (counter)
	{
		a = n % 10;
		n = n / 10;
		c[--counter] = a + 48;
	}
	return (c);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	a;
	int				counter;
	char			*c;

	counter = 1;
	a = n;
	while (a >= 10)
	{
		a = a / 10;
		counter++;
	}
	c = malloc(counter + 1);
	if (!c)
		return (NULL);
	return (ft_itoa2(counter, c, n));
}
