/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:08:51 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/14 02:51:59 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_zero(char *s, int i, va_list ap, char *str, t_num nmbr)
{
	int str_len;
	int only_numbers;
	int j;
	int k;

	only_numbers = 0;
	str_len = nmbr.len;
	j = i;
	while (ft_isdigit(s[j]) != 0)
		j++;
	k = j - i + 1;
	if (nmbr.only_numbers == 0)
		nmbr.only_numbers = ft_atoi(ft_substr(s, i, j - 1));
	if (s[j] == 'x' || s[j] == 'X')
		str_len -= 1;
	if (s[j] == 'p')
		str_len -= 3;
	if (str[0] == '-')
		str_len += 1;
	only_numbers = ft_atoi(str);
	if (nmbr.only_numbers <= str_len)
	{
		just_converting_int(s, j, ap, 0, only_numbers, 0);
		return(k + 2);
	}
	if (str[0] == '-')
		write(1, "-", 1);
	while (nmbr.only_numbers > str_len)
	{
		write(1, "0", 1);
		nmbr.only_numbers--;
	}
	if (str[0] == '-')
		just_converting_int(s, j, ap, 0, only_numbers, 1);
	else
		just_converting_int(s, j, ap, 0, only_numbers, 0);
	return (k + 2);
}

int		left_flag(char *s, int i, va_list ap, t_num kx, char *str)
{
	int j;
	int	number_take;
	unsigned long	take_arg;
	int k;

	j = i;
	take_arg = 0;

	while (ft_isdigit(s[j]) != 0)
		j++;
	k = j - i + 1;
	number_take = ft_atoi(ft_substr(s, i, j - 1));
	if (str && str[0] == '-')
	{
		take_arg = ft_atoi(str);
		just_converting_int(s, j, ap, 0, take_arg, 0);
		number_take -= 1;
	}
	else if (s[j] != 'c' && s[j] != 'p')
	{
		take_arg = ft_atoi(str);
		just_converting_int(s, j, ap, 0, take_arg, 0);
	}
	else if (s[j] == 'p')
		just_converting_int(s, j, ap, 0, kx.ul_num, 0);
	just_converting_char(s, j, ap, str);
	if (number_take <= kx.len)
		return (k + 2);
	while (number_take > kx.len)
	{
		write(1, " ", 1);
		number_take--;
	}
	return(k + 2);
}
