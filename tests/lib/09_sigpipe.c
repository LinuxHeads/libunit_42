/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sigpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:54:48 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/18 20:04:49 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_tests.h"

int	test_sigpipe(void)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	close(pipe_fd[0]);
	write(pipe_fd[1], "Hello", 5);
	close(pipe_fd[1]);
	return (0);
}
