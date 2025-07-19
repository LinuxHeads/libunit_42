/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_special_char_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:54:47 by malsharq          #+#    #+#             */
/*   Updated: 2025/07/19 14:41:33 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

int isalpha_special_char_test(void)
{
    if(ft_isalpha('$') == isalpha('$'))
        return (0);
    else
        return (1);
}