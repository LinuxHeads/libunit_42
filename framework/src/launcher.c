/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:02:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 11:27:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

static void	child_process(t_unit_test *test_node)
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
	exit(ret);
}

static char	*get_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			return (ft_strdup(YEL "SIGSEGV"));
		else if (WTERMSIG(status) == SIGBUS)
			return (ft_strdup(YEL "SIGBUS"));
		else if (WTERMSIG(status) == SIGABRT)
			return (ft_strdup(YEL "SIGABRT"));
		else if (WTERMSIG(status) == SIGFPE)
			return (ft_strdup(YEL "SIGFPE"));
		else if (WTERMSIG(status) == SIGILL)
			return (ft_strdup(YEL "SIGILL"));
		else if (WTERMSIG(status) == SIGPIPE)
			return (ft_strdup(YEL "SIGPIPE"));
		else if (WTERMSIG(status) == SIGALRM)
			return (ft_strdup(YEL "SIGALRM, the test timed out"));
	}
	else if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (ft_strdup(GRN "OK"));
		else
			return (ft_strdup(RED "KO"));
	}
	return (ft_strdup(RED "Unknown status"));
}

void	parent_process(t_unit_test *list, int *success_count)
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
		(*success_count)++;
	ft_printf(WHT "%s: %s: %s\n", list->function_name, list->test_name,
		status_str);
	free(status_str);
}

int	launch_tests(t_unit_test *list)
{
	pid_t		pid;
	int			total_tests;
	int			success_count;
	t_unit_test	*current;

	if (!list)
	{
		ft_printf("No tests to run.\n");
		return (0);
	}
	current = list;
	total_tests = 0;
	success_count = 0;
	while (current)
	{
		pid = fork();
		if (pid == 0)
			child_process(current);
		else
			parent_process(current, &success_count);
		current = current->next;
		total_tests++;
	}
	ft_printf(WHT "Total tests: %d," GRN " Success: %d" WHT "," RED " Failures: \
%d\n", total_tests, success_count, total_tests - success_count);
	free_list(list);
	if (success_count == total_tests)
		return (0);
	return (-1);
}
