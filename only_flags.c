/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:08:51 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/17 17:20:28 by molabhai         ###   ########.fr       */
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
	if (str[0] == '-')
		str_len += 1;
	only_numbers = ft_atoi(str);
	if (nmbr.dot_flag == 1)
		k -= 1;
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
	if (number_take == 0)
		number_take = kx.only_numbers;
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

int		width_flags(char *s, int i, va_list ap, t_num width, char *number)
{
	int j;
	int k;
	int	width_number;
	unsigned long _width;

	_width = 0;
	j = i;
	while (ft_isdigit(s[j]))
		j++;
	k = j - i;
	width_number = ft_atoi(ft_substr(s, i, j - 1));	
	if (width_number == 0)
		width_number = width.only_numbers;
	if (number)
		_width = ft_atoi(number);
	if (width.dot_flag == 1)
		j += 1;
	if (width_number <= width.len)
	{
		if (s[j] == 'x' || s[j] == 'X')
			just_converting_int(s, j, ap, 0, width.u_num, 0);
		else if (s[j] == 'p')
			just_converting_int(s, j, ap, 0, width.ul_num, 0);
		else
			just_converting_int(s, j, ap, 0, _width, 0);
		just_converting_char(s, j, ap, number);
		return (k + 2);
	}
	while (width_number > width.len)
	{
		write(1, " ", 1);
		width_number--;
	}
	if (s[j] == 'x' || s[j] == 'X')
		just_converting_int(s, j, ap, 0, width.u_num, 0);
	else if (s[j] == 'p')
		just_converting_int(s, j, ap, 0, width.ul_num, 0);
	else
		just_converting_int(s, j, ap, 0, _width, 0);
	just_converting_char(s, j, ap, number);
	return (k + 2);
}

int		dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int width_between;

	width_between = 0;
	if (ft_isdigit(s[i]))
	{
		if (check_for_convertion(s, i) == 6)
			width_between = dot_flag_helper_III(s, i, ap);
		else	
			width_between =  dot_flag_helper_I(s, i, ap, nmbr);
		return (width_between + 1);
	}
	if (check_for_convertion(s, i) == 6 && ft_isdigit(s[i + 1]))
	{
		width_between = dot_flag_helper_IIII(s, i, ap);	
		return (width_between + 1);
	}
	else if (ft_isdigit(s[i + 1]))
	{
		width_between = dot_flag_helper_II(s, i, ap, nmbr);
		return (width_between + 1);
	}
	if (s[i] == '.' &&  !ft_isdigit(s[i - 1]) && !ft_isdigit(s[i + 1]))
	{
		width_between = 2;
		if (check_for_convertion(s, i) == 6)
			width_between = dot_flag_helper_IIII(s, i, ap);	
		else
		{
			nmbr = for_dot_flag(s, i + 1, ap, nmbr);
			just_converting_int(s, i + 1, ap, 0, nmbr.only_numbers, 0);
		}
	}
	return(width_between + 1);
}