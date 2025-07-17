/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:35:40 by malsharq          #+#    #+#             */
/*   Updated: 2024/11/06 14:46:54 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_select2(va_list args, t_array s_flags, const char *conv, int count)
{
	int		sign;
	char	c[1];

	sign = 1;
	if (*conv == 'c')
	{
		*c = va_arg(args, int);
		if (*s_flags.flags == '\0')
			return (count++, write(1, c, 1));
		count += flags_hs(s_flags, c, 1);
		if (!ft_isprint(*c))
			count++;
	}
	else if (*conv == 'p')
		count += flags_hp(s_flags, va_arg(args, size_t));
	else if (*conv == 'u')
		count += flags_hu(s_flags, va_arg(args, unsigned int));
	else if (*conv == 'd' || *conv == 'i')
	{
		sign = 1;
		count += flags_hi(s_flags, va_arg(args, int), sign);
	}
	else
		count += write(1, "%%", 1);
	return (count);
}

int	ft_select(va_list args, const char *static_arg, const char *conv,
		const char *bflags)
{
	int		count;
	t_array	s_flags;
	int		tmp;

	count = 0;
	tmp = 0;
	while (ft_strchr(bflags, static_arg[tmp]) || static_arg[tmp] == '0')
		tmp++;
	s_flags.flags = ft_substr(static_arg, 0, conv - static_arg);
	s_flags = ft_findflags(s_flags, s_flags.flags, ft_atoi(static_arg + tmp));
	if (*conv == 's')
		tmp = flags_hs(s_flags, va_arg(args, char *), 0);
	else if (*conv == 'x')
		tmp = flags_hh(s_flags, va_arg(args, int), 1);
	else if (*conv == 'X')
		tmp = flags_hh(s_flags, va_arg(args, int), 0);
	else
	{
		tmp = ft_select2(args, s_flags, conv, count);
		if (tmp == -1)
			return (free(s_flags.flags), count);
	}
	count += tmp;
	return (free(s_flags.flags), count);
}

t_var	init(void)
{
	t_var	vars;

	vars.count = 0;
	vars.bflags = ft_strdup(" +#0-");
	vars.conv = ft_strdup("cspdiuxX%%");
	return (vars);
}

int	ft_printf(const char *static_arg, ...)
{
	t_var	vars;

	vars = init();
	va_start(vars.args, static_arg);
	if (!vars.bflags || !vars.conv)
		return (1);
	while (*static_arg != '\0')
	{
		if (*static_arg == '%')
		{
			vars.rev = 0;
			while (!ft_strchr(vars.conv, *(++static_arg)))
				vars.rev++;
			vars.rev = ft_select(vars.args, static_arg - vars.rev, static_arg,
					vars.bflags);
			if (vars.rev == -1)
				return (vars.count);
			vars.count += vars.rev;
		}
		else
			vars.count += write(1, static_arg, 1);
		static_arg++;
	}
	return (free(vars.conv), free(vars.bflags), va_end(vars.args), vars.count);
}
