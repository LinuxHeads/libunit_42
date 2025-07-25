/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:45:03 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 21:42:48 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int	ft_strcmp_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "identical_strings_test", &identical_string,
		VERBOSE);
	load_test(&test_list, "empty_string_test", &empty_string, VERBOSE);
	load_test(&test_list, "non_equal_strings_test", &non_equal_strings,
		VERBOSE);
	load_test(&test_list, "non_equal_strings_test_02", &non_equal_strings_2,
		VERBOSE);
	return (launch_tests(test_list, "FT_STRCMP"));
}
