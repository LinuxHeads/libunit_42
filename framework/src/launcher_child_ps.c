/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_child_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:11:10 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 19:56:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

void	child_process(t_unit_test *test_node, t_unit_test *list)
{
	int	devnull;
	int	ret;

	if (!test_node || !test_node->f)
	{
		ft_printf("Invalid test function.\n");
		exit(EXIT_FAILURE);
	}
	devnull = open("/dev/null", O_WRONLY);
	if (devnull >= 0)
	{
		dup2(devnull, STDOUT_FILENO);
		dup2(devnull, STDERR_FILENO);
		close(devnull);
	}
	alarm(TIMEOUT);
	ret = test_node->f();
	free_list(list);
	exit(ret);
}