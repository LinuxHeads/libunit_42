/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:31:59 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:54:03 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	basic_test(void)
{
	char	**str;

	str = ft_split("hello world !", ' ');
	if (strcmp("hello", str[0]) == 0 && strcmp("world", str[1]) == 0
		&& strcmp("!", str[2]) == 0 && str[3] == NULL)
		return (0);
	else
		return (1);
}
