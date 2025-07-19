/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:45:03 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:15:24 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int ft_strcmp_launcher(void)
{
    t_unit_test *test_list;

    test_list =NULL;
    load_test(&test_list, "ft_strcmp", "identical_strings_test", &identical_string);
    load_test(&test_list, "ft_strcmp", "empty_string_test", &empty_string);
    load_test(&test_list, "ft_strcmp", "non_equal_strings_test", &non_equal_strings);
    load_test(&test_list, "ft_strcmp", "non_equal_strings_test_02", &non_equal_strings_2);
    return (launch_tests(test_list));
}