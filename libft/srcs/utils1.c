/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:31:41 by malsharq          #+#    #+#             */
/*   Updated: 2024/11/06 15:50:48 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	prints(t_array flag, char *string, int nos, int max_c)
{
	int	count;
	int	min_width;

	count = max_c + nos;
	if (*string == '\0' && nos && max_c != 0)
		nos--;
	min_width = 2;
	while (min_width)
	{
		if (flag.iflags[4] == 0)
		{
			while (nos--)
				write(1, " ", 1);
			min_width--;
			if (min_width == 0)
				break ;
		}
		if (*string == 0 && flag.iflags[7] == 2)
			max_c++;
		write(1, string, max_c);
		flag.iflags[4] = 0;
		min_width--;
	}
	return (count);
}

int	helper_flags_hs(t_array flags, char *string, int flag, struct s_vflags list)
{
	if (list.nos < 0)
		list.nos = 0;
	if ((*string == '0' && flag > 1) || flag < 2)
	{
		if (ft_strchr(flags.flags, '.') && flags.iflags[1] == 0
			&& flags.iflags[0] > 1)
		{
			list.nos += list.max_c;
			list.max_c = 0;
		}
		if (ft_strchr(flags.flags, '.') && flags.iflags[1] == 0
			&& flags.iflags[0] == 0)
			list.max_c = 0;
	}
	if (flag == 1 && list.nos && *string == '\0')
	{
		flags.iflags[7] = 2;
		--list.nos;
	}
	if (ft_strncmp("(null)", string, 6) == 0 && list.max_c < 6 && flag == 0)
		list.max_c = 0;
	flag = prints(flags, string, list.nos, list.max_c);
	if (ft_strncmp("(null)", string, 6) == 0)
		free(string);
	return (flag);
}

int	flags_hs(t_array flags, char *string, int flag)
{
	struct s_vflags	list;

	if (string == NULL)
	{
		if (*flags.flags == '\0')
			return (write(1, "(null)", 6));
		else
		{
			string = ft_strdup("(null)");
			if (!string)
				return (-1);
		}
	}
	list.max_c = ft_strlen(string);
	if (flags.iflags[1] && flags.iflags[1] < list.max_c)
		list.max_c = flags.iflags[1];
	if (flag == 2 && flags.iflags[1] != 0)
		list.max_c = ft_strlen(string);
	list.nos = flags.iflags[0] - list.max_c;
	if ((int)ft_strlen(string) > flags.iflags[0] && flag > 1 && list.max_c != 1)
		return (write(1, string, ft_strlen(string)));
	return (helper_flags_hs(flags, string, flag, list));
}

int	flags_hp(t_array flags, size_t p)
{
	char	*pstring;

	if (p == 0)
	{
		pstring = ft_strdup("(nil)");
		if (!pstring)
			return (-1);
	}
	else
	{
		pstring = hitoa(p, 1);
		pstring = ft_strjoin(ft_strdup("0x"), pstring, 1);
		if (!pstring)
			return (-1);
	}
	if (flags.iflags[0] < (int)ft_strlen(pstring))
		flags.iflags[0] = (int)ft_strlen(pstring);
	flags.iflags[0] = flags_hs(flags, pstring, 2);
	return (free(pstring), flags.iflags[0]);
}

char	*zstring(char c, int size)
{
	char	*string;
	int		i;

	i = 0;
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	while (size--)
	{
		string[i] = c;
		i++;
	}
	string[i] = '\0';
	return (string);
}
