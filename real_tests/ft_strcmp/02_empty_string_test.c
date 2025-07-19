/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_string_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:07 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:28 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int	ft_strcmp_empty_string(void)
{
	if ((int)ft_strcmp("", "hello world") == strcmp("", "hello world"))
		return (0);
	else
		return (1);
}
