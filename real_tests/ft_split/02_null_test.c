/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:32:08 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 15:42:57 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int ft_split_null_test(void)
{
    char **str;
    
    str = ft_split(NULL ,' ');
    if (str == NULL)
        return(0);
    else 
        return(1);
}