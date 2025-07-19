/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_parent_ps_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:12:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 22:22:41 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit_bonus.h"

void	parent_process(t_unit_test *current, int *success_count,
		const char *function_name, int *pipe_fd)
{
	int		status;
	char	*status_str;
	int		passed;

	wait(&status);
	status_str = get_status(status);
	if (!status_str)
	{
		ft_printf("Memory allocation failed for status string.\n");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		passed = 1;
		if (current->flags & OUTPUT)
		{
			close(pipe_fd[1]);
			if (!compare_output(current->expected_out, pipe_fd[0]))
				passed = 0;
		}
		if (passed)
			(*success_count)++;
		if ((current->flags & OUTPUT) && passed == 0)
		{
			free(status_str);
			status_str = ft_strdup(RED "KO");
		}
	}
	if (current->flags & VERBOSE)
		ft_printf(WHT "%s: %s: %s\n", function_name, current->test_name,
			status_str);
	free(status_str);
}
