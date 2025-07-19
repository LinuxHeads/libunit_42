/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:32:08 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:54:09 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_split_null_test(void)
{
	char	**str;

	str = ft_split(NULL, ' ');
	if (str == NULL)
		return (0);
	else
		return (1);
}
