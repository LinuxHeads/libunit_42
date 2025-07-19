/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:53:18 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:53 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int	isalpha_null_test(void)
{
	if (ft_isalpha('\0') == isalpha('\0'))
		return (0);
	else
		return (1);
}
