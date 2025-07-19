/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:15:28 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 15:31:41 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int ft_split_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    load_test(&test_list, "ft_split", "basic_test", &basic_test);
    load_test(&test_list, "ft_split", "null_test", &null_test);
    load_test(&test_list, "ft_split", "empty_string", &empty_string);
    load_test(&test_list, "ft_split", "string_of_spaces", &string_of_spaces);
    return (launch_tests(test_list));
}