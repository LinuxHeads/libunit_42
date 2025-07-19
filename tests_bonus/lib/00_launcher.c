/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:00:00 by 38 by abdsa       #+#    #+#             */
/*   Updated: 2025/07/19 22:12:39 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;
	t_unit_test	*node;

	test_list = NULL;
	load_test(&test_list, "normal OK test", &test_success, VERBOSE);
	load_test(&test_list, "failing test", &test_fail, VERBOSE);
	load_test(&test_list, "segmentation fault test", &test_segfault, VERBOSE);
	load_test(&test_list, "bus error test", &test_sigbus, VERBOSE);
	load_test(&test_list, "timeout test", &test_timeout, VERBOSE);
	load_test(&test_list, "floating point exception test", &test_sigfpe,
		VERBOSE);
	load_test(&test_list, "abrt test", &test_sigabrt, VERBOSE);
	load_test(&test_list, "ill test", &test_sigill, VERBOSE);
	load_test(&test_list, "pipe test", &test_sigpipe, VERBOSE);
	load_test(&test_list, "pipe test", &test_sigpipe, VERBOSE);
	node = load_test(&test_list, "printf output test", &test_printf,
			VERBOSE | OUTPUT);
	if (!node)
	{
		free_list(test_list);
		return (1);
	}
	node->expected_out = "123";
	return (launch_tests(test_list, "LIBUNIT"));
}
