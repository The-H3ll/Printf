/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:18:23 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/13 23:46:17 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int       check_for_star(char *s, int i)
{
    int j;

    j = i;
    if (s[j] == '*')
        return (1);
    return (0);
}

static unsigned long     len(unsigned long number)
{
    unsigned long i;

    i = 0;
    while (number != 0)
    {
        number = number / 10;
        i++;
    }
    return (i);
}

static char     *ul_conversion(unsigned long number)
{
    char *str;
    char c;
    int  len_number;
    int take_number;

    len_number = len(number);
    take_number = 0;
    str = NULL;
    if (!(str = (char *)malloc(sizeof(char) * len_number + 1)))
        return (NULL);
    while (len_number > 0)
    {    
        take_number = number % 10;
        c = take_number + '0';
        str[len_number - 1] = c;
        number = number / 10;
        len_number--;
    }
    return(str);
}

char    *ul_itoi(unsigned long  number)
{
    char *str;

    str = NULL;
    str = ul_conversion(number);
    return (str);
}