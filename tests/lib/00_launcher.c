/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/18 01:27:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_tests.h"

int	launcher_lib(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "", &test_success);
	load_test(&test_list, "", &test_fail);
	load_test(&test_list, "", &test_segfault);
	load_test(&test_list, "", &test_sigbus);

	main_launcher(test_list);
	free_list(test_list);
	return (0);
}
