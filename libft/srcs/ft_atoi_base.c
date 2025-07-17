/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:29:00 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/24 21:57:39 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_power(int num, int power)
{
	if (power == 0)
		return (1);
	return (num * ft_power(num, power - 1));
}

int	expand(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 8) & 0xF;
	g = (color >> 4) & 0xF;
	b = color & 0xF;
	r = (r << 4) | r;
	g = (g << 4) | g;
	b = (b << 4) | b;
	return ((r << 16) | (g << 8) | b);
}

int	ft_atoi_base(char *str, int base, int sign)
{
	int	len;
	int	num;
	int	current;
	int	count;

	num = 0;
	count = 0;
	if (ft_strnstr(str, "0x", 2) || ft_strnstr(str, "0X", 2))
		str += 2;
	len = ft_strlen(str) - 1;
	while (len > -1)
	{
		if (ft_isdigit(str[len]))
			current = str[len] - '0';
		else if (ft_isalpha(str[len]))
			current = ft_toupper(*(str + len)) - 'A' + 10;
		num += current * ft_power(base, count++);
		len--;
	}
	if (ft_strlen(str) == 3)
		num = expand(num);
	return (sign * num);
}
