/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:16:43 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 21:42:25 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isdigit.h"

int	ft_isdigit_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "char_test", &char_test, VERBOSE);
	load_test(&test_list, "null_test", &null_test, VERBOSE);
	load_test(&test_list, "digit_test", &digit_test, VERBOSE);
	load_test(&test_list, "special_char_test", &special_char_test,
		VERBOSE);
	return (launch_tests(test_list, "FT_ISDIGIT"));
}
