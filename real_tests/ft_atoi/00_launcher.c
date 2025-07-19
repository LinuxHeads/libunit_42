/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:33:01 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:39:01 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int ft_atoi_launcher(void)
{
    t_unit_test *test_list;

    test_list =NULL;
    load_test(&test_list, "ft_atoi", "basic_test", &basic_test);
    load_test(&test_list, "ft_atoi", "zero_test", &zero_test);
    load_test(&test_list, "ft_atoi", "min_int_test", &min_int_test);
    load_test(&test_list, "ft_atoi", "max_int", &max_int_test);
    return (launch_tests(test_list));
}