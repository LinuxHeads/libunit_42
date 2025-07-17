/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:04:13 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/10 16:45:11 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

static char	*ft_itoa2(int counter, char *c, int n, int b)
{
	int	a;

	a = n;
	c[counter] = '\0';
	if (b == 1)
		c[0] = '-';
	while (counter)
	{
		if (b == 1 && counter == 1)
			break ;
		a = n % 10;
		n = n / 10;
		c[--counter] = a + 48;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		a;
	int		b;
	int		counter;
	char	*c;

	b = 0;
	counter = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		b = 1;
		counter++;
	}
	a = n;
	while (a >= 10)
	{
		a = a / 10;
		counter++;
	}
	c = malloc(counter + 1);
	if (!c)
		return (NULL);
	return (ft_itoa2(counter, c, n, b));
}
