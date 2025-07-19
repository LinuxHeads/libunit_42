/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:32:51 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:32:54 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int ft_isalpha_launcher(void)
{
    t_unit_test *test_list;

    test_list =NULL;
    load_test(&test_list, "ft_isalpha", "char_test", &isalpha_char_test);
    load_test(&test_list, "ft_isalpha", "null_test", &isalpha_null_test);
    load_test(&test_list, "ft_isalpha", "digit_test", &isalpha_digit_test);
    load_test(&test_list, "ft_isalpha", "special_char_test", &isalpha_special_char_test);
    return (launch_tests(test_list));
}