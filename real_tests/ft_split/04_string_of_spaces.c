/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_string_of_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:32:10 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 15:38:31 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int string_of_spaces(void)
{
    char **str;
    
    str = ft_split("                 ",' ');
    if (str[0] == NULL)
        return(0);
    else 
        return(1);
}