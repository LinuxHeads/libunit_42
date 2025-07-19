/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:15:28 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 17:17:37 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_split_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "basic_test", &basic_test, 1);
	load_test(&test_list, "null_test", &null_test, 1);
	load_test(&test_list, "empty_string", &empty_string, 1);
	load_test(&test_list, "string_of_spaces", &string_of_spaces, 1);
	return (launch_tests(test_list, "FT_SPLIT"));
}
