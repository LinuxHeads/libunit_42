/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_string_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:07 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:14:36 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int ft_strcmp_empty_string(void)
{
    if ((int)ft_strcmp("", "hello world") == strcmp("", "hello world"))
        return (0);
    else
        return (1);
}
