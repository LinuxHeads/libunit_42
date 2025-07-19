/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_special_char_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:54:47 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int	isalpha_special_char_test(void)
{
	if (ft_isalpha('$') == isalpha('$'))
		return (0);
	else
		return (1);
}
