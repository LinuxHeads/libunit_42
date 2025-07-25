/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:29:29 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 20:13:51 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TESTS_H
# define LIB_TESTS_H

# include "../framework/include/libunit.h"
# include <stdlib.h>
# include <unistd.h>

int	test_success(void);
int	test_fail(void);
int	test_segfault(void);
int	test_sigbus(void);
int	launcher_lib(void);

#endif
