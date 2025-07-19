/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 21:37:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libunit.h"

static t_unit_test	*add_node(t_unit_test **test_list, const char *test_name,
		int (*f)(void), int flags)
{
	t_unit_test	*new_node;
	t_unit_test	*cursor;

	new_node = malloc(sizeof(t_unit_test));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->f = f;
	new_node->test_name = test_name;
	new_node->flags = flags;
	new_node->next = NULL;
	if (!test_list || !*test_list)
	{
		*test_list = new_node;
		return (new_node);
	}
	cursor = *test_list;
	while (cursor->next)
	{
		cursor = cursor->next;
	}
	cursor->next = new_node;
	return (new_node);
}

void	free_list(t_unit_test *list)
{
	t_unit_test	*cur;
	t_unit_test	*tmp;

	if (!list)
	{
		return ;
	}
	cur = list;
	tmp = list;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

t_unit_test	*load_test(t_unit_test **test_list, const char *test_name,
		int (*f)(void), int flags)
{
	t_unit_test	*node;

	node = add_node(test_list, test_name, f, flags);
	if (node == NULL)
	{
		if (test_list)
			free_list(*test_list);
		exit(1);
	}
	return (node);
}
