/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 10:39:27 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;
	
	test_list = NULL;
	load_test(&test_list, "LIBUNIT", "normal OK test", &test_success);
	load_test(&test_list, "LIBUNIT", "failing test", &test_fail);
	load_test(&test_list, "LIBUNIT", "segmentation fault test", &test_segfault);
	load_test(&test_list, "LIBUNIT", "bus error test", &test_sigbus);
	load_test(&test_list, "LIBUNIT", "timeout test", &test_timeout);
	load_test(&test_list, "LIBUNIT", "floating point exception test",
		&test_sigfpe);
	load_test(&test_list, "LIBUNIT", "abrt test", &test_sigabrt);
	load_test(&test_list, "LIBUNIT", "ill test", &test_sigill);
	load_test(&test_list, "LIBUNIT", "pipe test", &test_sigpipe);
	return (launch_tests(test_list));
}
