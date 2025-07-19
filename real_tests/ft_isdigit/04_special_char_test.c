/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_special_char_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:54:47 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 14:22:12 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isdigit.h"

int special_char_test(void)
{
    if(ft_isdigit('$') == isdigit('$'))
        return (0);
    else
        return (1);
}