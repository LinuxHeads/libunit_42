/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:58:15 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/17 20:15:27 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

int f(void)
{
    printf("hi\n");

    return (1);
}

int main(void)
{
    t_unit_test *list = NULL;

    load_test(&list, "1", f);
    load_test(&list, "2", f);
    load_test(&list, "3", f);
    load_test(&list, "4", f);
    load_test(&list, "5", f);

    printf("list head %s\n", list->test_name);
    t_unit_test *head = list;
    while(list->next)
    {
        list = list->next;
    }
    printf("list tail %s\n", list->test_name);

    free_list(head);
    return (0);
}
