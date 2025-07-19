/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_non_equal_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:44 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int	non_equal_strings(void)
{
	if (ft_strcmp("hello", "hello world") != 0)
		return (0);
	else
		return (1);
}
