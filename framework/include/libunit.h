/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:42:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 15:52:41 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

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

typedef struct s_unit_test
{
	int					verbose;
	int					(*f)(void);
	const char			*test_name;
	struct s_unit_test	*next;
}						t_unit_test;

void					free_list(t_unit_test *list);
void					load_test(t_unit_test **test_list,
							const char *test_name, int (*f)(void), int verbose);
int						launch_tests(t_unit_test *list,
							const char *function_name);
#endif