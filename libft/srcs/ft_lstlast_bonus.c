/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:40:46 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/13 18:40:50 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	while (lst)
	{
		last = lst;
		lst = lst->next;
		if (!lst)
		{
			lst = last;
			break ;
		}
	}
	return (lst);
}
