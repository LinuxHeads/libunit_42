/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:29:51 by abdsalah          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/19 16:39:22 by malsharq         ###   ########.fr       */
=======
/*   Updated: 2025/07/19 15:54:36 by abdsalah         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "project_tests.h"
// int ft_isalnum_launcher(void);
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
	if (!ft_lstfind(skip_list, "ft_isdigit"))
		ft_isdigit_launcher();
	if (!ft_lstfind(skip_list, "ft_isalpha"))
		ft_isalpha_launcher();
	if (!ft_lstfind(skip_list, "ft_split"))
		ft_split_launcher();
	if (!ft_lstfind(skip_list, "ft_strcmp"))
		ft_strcmp_launcher();
	if (!ft_lstfind(skip_list, "ft_atoi"))
		ft_atoi_launcher();
	if (flag)
	{
		ft_lstclear(&skip_list, free);
	}
	return (0);
}
