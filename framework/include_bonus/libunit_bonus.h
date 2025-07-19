/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:42:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 19:59:26 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>

# define TIMEOUT 5
# define YEL "\033[0;33m"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define WHT "\033[0;37m"
# define VERBOSE 0b010
# define OUTPUT 0b100

typedef struct s_unit_test
{
	int					flags;
	int					(*f)(void);
	const char			*test_name;
	const char			*expected_out;
	struct s_unit_test	*next;
}						t_unit_test;

void					free_list(t_unit_test *list);
t_unit_test				*load_test(t_unit_test **test_list,
							const char *test_name, int (*f)(void), int verbose);
int						launch_tests(t_unit_test *list,
							const char *function_name);
int						compare_output(const char *out, int fd);
char					*get_status(int status);
void					child_process(t_unit_test *test_node, t_unit_test *list,
							int *pipe_fd);
void					parent_process(t_unit_test *current, int *success_count,
							const char *function_name, int *pipe_fd);
#endif