/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:17:48 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/16 07:03:11 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int     for_digit_flag(char *s, int i, va_list ap, t_num nmbr)
{
    char *number;
    int    flag_num;
    int     who;
    int     j;
    char *ss;

    j = 0;
	if (check_for_star(s, i) == 1)
	{
		nmbr.only_numbers = va_arg(ap, int);
		i += 1;
		j = 1;
	}
	who = check_for_convertion(s, i);
	if (who == 1)
	{
		nmbr.num = va_arg(ap, int);
		nmbr.len = nmbr_count(nmbr.num);
		number = ft_itoa(nmbr.num);
		if (number[0] == '-')
			nmbr.len += 1;
		flag_num = 	width_flags(s, i, ap, nmbr, number);
	}
	if (who == 2)
	{
		nmbr.l_num = va_arg(ap, long);
		nmbr.len = nmbr_count(nmbr.l_num);
		number = ft_itoa(nmbr.l_num);
		flag_num = width_flags(s, i, ap, nmbr, number);
	}
	if (who == 3 || who == 4)
	{
		nmbr.u_num = va_arg(ap, unsigned int);
		nmbr.len = nmbr_count(nmbr.u_num);
		if (nmbr.len == 10)
			nmbr.len -= 2;
		else
			nmbr.len -= 1;
		flag_num = width_flags(s, i, ap, nmbr, NULL);
	}
	if (who == 5)
	{
		nmbr.ul_num = va_arg(ap, unsigned long);
		nmbr.len = nmbr_count(nmbr.ul_num) + 1;
		flag_num = width_flags(s, i, ap, nmbr, NULL);
	}
	if (who == 6)
	{
		ss = ft_strdup(va_arg(ap, char *));
		nmbr.len = ft_strlen(ss);
		flag_num = width_flags(s, i, ap, nmbr, ss);
	}
	if (who == 7)
	{
		nmbr.len = 1;
		flag_num = width_flags(s, i, ap, nmbr, NULL);
	}
	if (j == 1)
		flag_num += 1;
    return (flag_num);
}

int     for_left_flag(char *s, int i, va_list ap, t_num nmbr)
{
 	char *number;
    int    flag_num;
    int     who;
    int     j;
    char *ss;

	j = 0;
		if (check_for_star(s, i + 1) == 1)
		{
			nmbr.only_numbers = va_arg(ap, int);
				i += 1;
				j = 1;
		}
		who = check_for_convertion(s, i);
		if (who == 1)
		{
			nmbr.num = va_arg(ap, int);
			nmbr.len = nmbr_count(nmbr.num);
			number = ft_itoa(nmbr.num);
			flag_num = left_flag(s, i + 1, ap, nmbr, number);
		}
		if (who == 2)
		{
			nmbr.l_num = va_arg(ap, long);
			nmbr.len = nmbr_count(nmbr.l_num);
			number = ft_itoa(nmbr.l_num);
			flag_num = left_flag(s, i + 1, ap, nmbr, number);
		}
		if (who == 3 || who == 4)
		{
			nmbr.u_num = va_arg(ap, unsigned int);
			nmbr.len = nmbr_count(nmbr.u_num);
			if (nmbr.len == 10)
				nmbr.len -= 2;
			else
				nmbr.len -= 1;	
			number = ul_itoi(nmbr.u_num);
			flag_num = left_flag(s, i + 1, ap, nmbr, number);
		}
		if (who == 5)
		{
			nmbr.ul_num = va_arg(ap, unsigned long);
			nmbr.len = nmbr_count(nmbr.ul_num) + 1;
			flag_num = left_flag(s, i + 1, ap, nmbr, number);
		}
		if (who == 6)
		{
			ss = ft_strdup(va_arg(ap, char *));
			nmbr.len = ft_strlen(ss);
			flag_num = left_flag(s, i + 1, ap, nmbr, ss);
		}
		if (who == 7)
		{
			nmbr.len = 1;
			flag_num = left_flag(s, i + 1, ap, nmbr, NULL);
		}
		if (j == 1)
			flag_num +=  1;
	return (flag_num);
}

int		for_zero_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	char *number;
	int who;
	unsigned long k;
	int flag_num;

	k = 0;
	j = 0;
	if (check_for_star(s, i) == 1)
	{
		nmbr.only_numbers = va_arg(ap, int);
		i += 1;
		j = 1;
	}
	who = check_for_convertion(s, i);
	if (who == 1)
	{
		k = va_arg(ap, int);
		nmbr.len = nmbr_count(k);
		number = ft_itoa(k);
		//printf("number == %s\n", number);
	}
	if (who == 3 || who == 4)
	{
		k = va_arg(ap, unsigned int);
		nmbr.len = nmbr_count(k);
		if (nmbr.len == 10)
			nmbr.len -= 2;
		else
			nmbr.len -= 1;
		number = ul_itoi(k);
	}
	if (who == 2)
	{
		k = va_arg(ap, long);
		nmbr.len = nmbr_count(k);
		number = ft_itoa(k);
	}
	flag_num = flag_zero((char *)s, i, ap, number, nmbr);
	if (j == 1)
		flag_num += 1;
	return (flag_num);
}