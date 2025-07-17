/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:42:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/17 20:13:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_unit_test
{
    int                 verbose;
    int                 (*f)(void);
    const char          *test_name;
    struct s_unit_test  *next;
} t_unit_test;

void    free_list(t_unit_test *list);
void    load_test(t_unit_test **test_list, const char *test_name, int (*f)(void));

#endif 