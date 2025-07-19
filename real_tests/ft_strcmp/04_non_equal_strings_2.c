/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_non_equal_strings_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:07:13 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:29:10 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_strcmp.h"

int non_equal_strings_2(void)
{
    if (ft_strcmp("hello world", "hello") != 0)
        return (0);
    else
        return (1);
}