/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:33:01 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 21:17:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_atoi_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "basic_test", &basic_test, VERBOSE);
	load_test(&test_list, "zero_test", &zero_test, VERBOSE);
	load_test(&test_list, "min_int_test", &min_int_test, VERBOSE);
	load_test(&test_list, "max_int", &max_int_test, VERBOSE);
	return (launch_tests(test_list, "FT_ATOI"));
}
