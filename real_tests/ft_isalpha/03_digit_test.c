/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_digit_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:54:08 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:55 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int	isalpha_digit_test(void)
{
	if (ft_isalpha('6') == isalpha('6'))
		return (0);
	else
		return (1);
}
