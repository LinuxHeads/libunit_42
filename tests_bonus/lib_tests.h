/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:29:29 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 22:06:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TESTS_BONUS_H
# define LIB_TESTS_BONUS_H

# include "../framework/include_bonus/libunit_bonus.h"
# include <stdlib.h>
# include <unistd.h>

int	test_success(void);
int	test_fail(void);
int	test_segfault(void);
int	test_sigbus(void);
int	launcher_lib(void);
int	test_timeout(void);
int	test_sigfpe(void);
int	test_sigabrt(void);
int	test_sigill(void);
int	test_sigpipe(void);
int	test_printf(void);

#endif
