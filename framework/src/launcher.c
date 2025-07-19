/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:02:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 21:37:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

static int	exec_tests(t_unit_test *list, const char *function_name,
		int *total_tests)
{
	int			success_count;
	pid_t		pid;
	t_unit_test	*current;

	current = list;
	success_count = 0;
	while (current)
	{
		pid = fork();
		if (pid == 0)
			child_process(current, list);
		else
			parent_process(current, &success_count, function_name);
		current = current->next;
		(*total_tests)++;
	}
	return (success_count);
}

int	launch_tests(t_unit_test *list, const char *function_name)
{
	int	total_tests;
	int	success_count;

	if (!list)
	{
		ft_printf("No tests to run.\n");
		return (0);
	}
	total_tests = 0;
	success_count = exec_tests(list, function_name, &total_tests);
	ft_printf(WHT "Total tests: %d," GRN " Success: %d" WHT "," RED " Failures: \
%d\n", total_tests, success_count, total_tests - success_count);
	free_list(list);
	if (success_count == total_tests)
		return (0);
	return (-1);
}
