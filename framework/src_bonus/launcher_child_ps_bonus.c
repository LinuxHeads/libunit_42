/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_child_ps_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:11:10 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 22:22:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit_bonus.h"

void	child_process(t_unit_test *test_node, t_unit_test *list, int *pipe_fd)
{
	int	devnull;
	int	ret;

	if (!test_node || !test_node->f)
	{
		ft_printf("Invalid test function.\n");
		exit(EXIT_FAILURE);
	}
	if (!(test_node->flags & OUTPUT))
	{
		devnull = open("/dev/null", O_WRONLY);
		if (devnull == -1)
		{
			free_list(list);
			exit(1);
		}
	}
	if (test_node->flags & OUTPUT)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	else
	{
		dup2(devnull, STDOUT_FILENO);
		close(devnull);
	}
	alarm(TIMEOUT);
	ret = test_node->f();
	free_list(list);
	exit(ret);
}
