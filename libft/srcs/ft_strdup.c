/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:15:03 by malsharq          #+#    #+#             */
/*   Updated: 2024/12/21 20:19:55 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ss;

	ss = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	ft_strlcpy(ss, s, (ft_strlen(s) + 1) * sizeof(char));
	return (ss);
}
