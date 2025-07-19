/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 15:54:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;
	
	test_list = NULL;
	load_test(&test_list, "normal OK test", &test_success, 1);
	load_test(&test_list, "failing test", &test_fail, 1);
	load_test(&test_list, "segmentation fault test", &test_segfault, 1);
	load_test(&test_list, "bus error test", &test_sigbus, 1);
	load_test(&test_list, "timeout test", &test_timeout, 1);
	load_test(&test_list, "floating point exception test",
		&test_sigfpe, 1);
	load_test(&test_list, "abrt test", &test_sigabrt, 1);
	load_test(&test_list, "ill test", &test_sigill, 1);
	load_test(&test_list, "pipe test", &test_sigpipe, 1);
	return (launch_tests(test_list, "LIBUNIT"));
}
