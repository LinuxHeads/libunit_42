/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_parent_ps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:12:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 19:58:11 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"


void	parent_process(t_unit_test *current, int *success_count,
		const char *function_name)
{
	int		status;
	char	*status_str;
	
	wait(&status);
	status_str = get_status(status);
	if (!status_str)
	{
		ft_printf("Memory allocation failed for status string.\n");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
			(*success_count)++;
	}
	if (current->flags & VERBOSE)
		ft_printf(WHT "%s: %s: %s\n", function_name, current->test_name,
				status_str);
	free(status_str);
}
