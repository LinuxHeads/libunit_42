/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/VERBOSE9 20:31:38 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 20:33:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests_bonus.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "normal OK test", &test_success, VERBOSE);
	load_test(&test_list, "failing test", &test_fail, VERBOSE);
	load_test(&test_list, "segmentation fault test", &test_segfault, VERBOSE);
	load_test(&test_list, "bus error test", &test_sigbus, VERBOSE);
	load_test(&test_list, "timeout test", &test_timeout, VERBOSE);
	load_test(&test_list, "floating point exception test",
		&test_sigfpe, VERBOSE);
	load_test(&test_list, "abrt test", &test_sigabrt, VERBOSE);
	load_test(&test_list, "ill test", &test_sigill, VERBOSE);
	load_test(&test_list, "pipe test", &test_sigpipe, VERBOSE);
	return (launch_tests(test_list, "LIBUNIT"));
}
