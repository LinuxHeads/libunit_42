/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:32:51 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:49 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int	ft_isalpha_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "char_test", &isalpha_char_test, 1);
	load_test(&test_list, "null_test", &isalpha_null_test, 1);
	load_test(&test_list, "digit_test", &isalpha_digit_test, 1);
	load_test(&test_list, "special_char_test", &isalpha_special_char_test, 1);
	return (launch_tests(test_list, "FT_ISALPHA"));
}
