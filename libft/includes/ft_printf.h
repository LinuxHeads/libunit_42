/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:13:33 by malsharq          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:05 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

struct		s_vflags
{
	int		max_c;
	int		left;
	int		nos;
	int		tmp;
};

typedef struct s_array
{
	int		iflags[8];
	char	*flags;
}			t_array;
typedef struct s_var
{
	va_list	args;
	char	*conv;
	int		rev;
	int		count;
	char	*bflags;
}			t_var;
char		*ft_uitoa(unsigned int n);
int			prints(t_array flag, char *string, int nos, int max_c);
int			helper_flags_hs(t_array flags, char *string, int flag,
				struct s_vflags list);
int			flags_hs(t_array flags, char *string, int flag);
int			flags_hp(t_array flags, size_t p);
char		*zstring(char c, int size);
int			flags_hi(t_array flags, int number, int sign);
int			flags_hu(t_array flags, unsigned int unumber);
int			flags_hh(t_array flags, unsigned int unumber, int flag);
char		*helper(char *hstring, int *iflags, size_t min, int flag);
t_array		ft_findflags(t_array s_flags, char *flags, int min_width);
char		*hitoa(size_t n, int flag);
int			prints(t_array flag, char *string, int nos, int max_c);
char		*zstring(char c, int size);
char		*helper(char *hstring, int *iflags, size_t min, int flag);
int			ft_select(va_list args, const char *static_arg, const char *conv,
				const char *convs);
int			ft_printf(const char *fmt, ...) __attribute__((format(printf, 1,
						2)));
#endif
