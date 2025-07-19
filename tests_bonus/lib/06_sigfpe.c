/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_sigfpe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:35:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 22:12:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	test_sigfpe(void)
{
	int	a;
	int	b;
	int	result;

	a = 1;
	b = 0;
	result = a / b;
	(void)result;
	return (0);
}
