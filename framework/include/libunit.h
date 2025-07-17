/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:42:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/17 21:13:51 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <signal.h>
# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"
typedef struct s_unit_test
{
    int                 verbose;
    int                 (*f)(void);
    const char          *test_name;
    struct s_unit_test  *next;
} t_unit_test;

void    free_list(t_unit_test *list);
void    load_test(t_unit_test **test_list, const char *test_name, int (*f)(void));
void     main_launcher(t_unit_test *list);
#endif 