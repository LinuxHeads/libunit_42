/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_identical_string_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:56:16 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:25 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int	identical_string(void)
{
	if (ft_strcmp("hello world", "hello world") == 0)
		return (0);
	else
		return (1);
}
