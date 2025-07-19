/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_identical_string_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:56:16 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 16:00:21 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

int identical_string(void)
{
    if (ft_strcmp("hello world", "hello world") == 0)
        return (0);
    else
        return (1);
}