/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:31:35 by malsharq          #+#    #+#             */
/*   Updated: 2024/11/06 15:51:47 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*helper(char *hstring, int *iflags, size_t min, int flag)
{
	int	noz;

	if (flag == 0)
	{
		if (iflags[2])
			min -= 2;
	}
	noz = min - ft_strlen(hstring);
	if (flag == 1)
	{
		if (iflags[6] || iflags[5])
			noz--;
	}
	if (noz > 0)
	{
		hstring = ft_strjoin(zstring('0', noz), (const char *)hstring, 1);
		if (!hstring)
			return (NULL);
	}
	return (hstring);
}

int	flags_hh(t_array flags, unsigned int unumber, int flag)
{
	char	*hstring;
	size_t	min;

	hstring = hitoa(unumber, flag);
	min = flags.iflags[0];
	if (flags.iflags[1])
		min = flags.iflags[1];
	if (min < ft_strlen(hstring))
		min = ft_strlen(hstring);
	if (flags.iflags[1] || flags.iflags[3])
		hstring = helper(hstring, flags.iflags, min, 0);
	if (!flags.iflags[7])
		flags.iflags[0] = ft_strlen(hstring);
	if (flags.iflags[2])
	{
		if (flag == 1 && (ft_strlen(hstring) != 1 || *hstring != '0'))
			hstring = ft_strjoin(ft_strdup("0x"), hstring, 1);
		else if (flag == 0 && (ft_strlen(hstring) != 1 || *hstring != '0'))
			hstring = ft_strjoin(ft_strdup("0X"), hstring, 1);
		if (!hstring)
			return (-1);
		if (flags.iflags[1])
			flags.iflags[0] -= 2;
	}
	return (min = flags_hs(flags, hstring, 2), free(hstring), min);
}

int	flags_hu(t_array flags, unsigned int unumber)
{
	char	*hstring;
	size_t	min;

	hstring = ft_uitoa(unumber);
	if (!hstring)
		return (-1);
	min = flags.iflags[0];
	if (flags.iflags[1])
		min = flags.iflags[1];
	if (min < ft_strlen(hstring))
		min = ft_strlen(hstring);
	if (flags.iflags[1] || flags.iflags[3])
		hstring = helper(hstring, flags.iflags, min, 1);
	if (flags.iflags[7] == 0)
		flags.iflags[0] = ft_strlen(hstring);
	min = flags_hs(flags, hstring, 2);
	return (free(hstring), min);
}

int	flags_hi(t_array flags, int number, int sign)
{
	char	*hstring;
	size_t	min;

	if (0 > number && (flags.iflags[3] || flags.iflags[1]) && INT_MIN != number)
		sign = -1;
	hstring = ft_itoa(sign * number);
	min = flags.iflags[0];
	if (flags.iflags[1])
		min = flags.iflags[1];
	if (min < ft_strlen(hstring))
		min = ft_strlen(hstring);
	if (sign == -1 && flags.iflags[3])
		min--;
	if (flags.iflags[1] || flags.iflags[3])
		hstring = helper(hstring, flags.iflags, min, 1);
	if (number >= 0 && flags.iflags[6])
		hstring = ft_strjoin(ft_strdup("+"), hstring, 1);
	if (sign == -1)
		hstring = ft_strjoin(ft_strdup("-"), hstring, 1);
	if (flags.iflags[5] && number >= 0)
		hstring = ft_strjoin(ft_strdup(" "), hstring, 1);
	if (!hstring)
		return (-1);
	return (min = flags_hs(flags, hstring, 2), free(hstring), min);
}

t_array	ft_findflags(t_array s_flags, char *flags, int min_width)
{
	int	i;

	i = 0;
	while (i < 8)
		s_flags.iflags[i++] = 0;
	s_flags.iflags[0] = min_width;
	if (*flags == '\0')
		return (s_flags);
	if (ft_strchr(flags, '.'))
		s_flags.iflags[1] = ft_atoi(ft_strchr(flags, '.') + 1);
	if (ft_strchr(flags, '#'))
		s_flags.iflags[2] = 1;
	if (*flags == '0' || ((ft_strchr(flags, '0')
				&& !ft_isdigit(*(ft_strchr(flags, '0') - 1)))))
		s_flags.iflags[3] = ft_atoi(ft_strchr(flags, '0') + 1);
	if (ft_strchr(flags, '-'))
		s_flags.iflags[4] = ft_atoi(ft_strchr(flags, '-') + 1);
	if (ft_strchr(flags, ' '))
		s_flags.iflags[5] = 1;
	if (ft_strchr(flags, '+'))
		s_flags.iflags[6] = 1;
	s_flags.iflags[7] = 1;
	return (s_flags);
}
