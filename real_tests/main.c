/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:29:51 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/19 13:57:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_tests.h"

static int ft_lstfind(t_list *list, char *target)
{
	t_list *cur;

	if (!list)
	{
		return (0);
	}
	cur = list;
	while (cur)
	{
		if (!ft_strcmp((char *)cur->content, target))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		flag;
	char	*test_name;
	t_list	*skip_list;
	
	i = 0;
	flag = 0;
	skip_list = NULL;
	if (ac > 1)
		flag = 1;
	if (flag && ft_strcmp(av[1], "-s") == 0)
	{
		i = 2;
		while (i < ac)
		{
			test_name = ft_strdup(av[i]);
			if (!test_name)
			{
				ft_lstclear(&skip_list, free);
				ft_printf("malloc failed :(.\n");
				exit(1);
			}
			ft_lstadd_back(&skip_list, ft_lstnew(test_name));
			i++;
		}
	}
	else if (flag)
	{
		ft_printf("Invalid option: %s\nUsage: ./lib_tests [-s] [tests to skip]...\n", av[1]);
		ft_lstclear(&skip_list, free);
		exit(1);
	}
	if (!ft_lstfind(skip_list, "libunit"))
		launcher_lib();
	if (flag)
	{
		ft_lstclear(&skip_list, free);
	}
	return (0);
}
