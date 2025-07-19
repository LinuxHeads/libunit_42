/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:07:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 19:09:21 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

int compare_output(const char *out, int fd)
{
    int i;
    char c;
    ssize_t n;

	i = 0;
    while ((n = read(fd, &c, 1)) > 0)
    {
        if (out[i++] != c)
        {
            close(fd);
            return (0);
        }
    }
    close(fd);
    return (out[i] == '\0');
}

char	*get_status(int status)
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
