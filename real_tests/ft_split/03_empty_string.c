/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_empty_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:32:05 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:54:11 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	empty_string(void)
{
	char	**str;

	str = ft_split("", ' ');
	if (str[0] == NULL)
		return (0);
	else
		return (1);
}
