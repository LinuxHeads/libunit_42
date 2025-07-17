/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:40:12 by malsharq          #+#    #+#             */
/*   Updated: 2024/10/31 21:35:15 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_itoa2(int counter, char *c, size_t n, int b)
{
	int		a;
	char	*hex;

	a = n;
	hex = "0123456789abcdef";
	c[counter] = '\0';
	if (b == 1)
		c[0] = '-';
	while (counter)
	{
		if (b == 1 && counter == 1)
			break ;
		a = n % 16;
		n = n / 16;
		c[--counter] = hex[a];
	}
	return (c);
}

static char	*ft_itoa3(int counter, char *c, size_t n, int b)
{
	int		a;
	char	*hex;

	a = n;
	hex = "0123456789ABCDEF";
	c[counter] = '\0';
	if (b == 1)
		c[0] = '-';
	while (counter)
	{
		if (b == 1 && counter == 1)
			break ;
		a = n % 16;
		n = n / 16;
		c[--counter] = hex[a];
	}
	return (c);
}

char	*hitoa(size_t n, int flag)
{
	size_t	a;
	size_t	b;
	int		counter;
	char	*c;

	b = 0;
	counter = 1;
	a = n;
	while (a >= 16)
	{
		a = a / 16;
		counter++;
	}
	c = malloc(counter + 1);
	if (!c)
		return (NULL);
	if (flag == 1)
		return (ft_itoa2(counter, c, n, b));
	else
		return (ft_itoa3(counter, c, n, b));
}
