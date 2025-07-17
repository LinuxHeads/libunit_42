/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/17 20:51:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_tests.h"

int launcher_lib()
{
    t_unit_test **test_list;
    
    load_test(test_list, "", &test_success);
    load_test(test_list, "", &test_fail);
    load_test(test_list, "", &test_segfault);
    load_test(test_list, "", &test_sigbus);

    return (0);
}