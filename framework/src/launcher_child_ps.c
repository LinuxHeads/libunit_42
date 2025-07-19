/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_child_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:11:10 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 20:44:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

void	child_process(t_unit_test *test_node, t_unit_test *list)
{
	int	ret;

	if (!test_node || !test_node->f)
	{
		ft_printf("Invalid test function.\n");
		exit(EXIT_FAILURE);
	}
	alarm(TIMEOUT);
	ret = test_node->f();
	free_list(list);
	exit(ret);
}