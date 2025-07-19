/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 21:41:36 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "normal OK test", &test_success, VERBOSE);
	load_test(&test_list, "failing test", &test_fail, VERBOSE);
	load_test(&test_list, "segmentation fault test", &test_segfault,
		VERBOSE);
	load_test(&test_list, "bus error test", &test_sigbus, VERBOSE);
	return (launch_tests(test_list, "LIBUNIT"));
}
