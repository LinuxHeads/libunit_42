/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_non_equal_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:44 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:29:02 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int non_equal_strings(void)
{
    if (ft_strcmp("hello", "hello world") != 0)
        return (0);
    else
        return (1);
}