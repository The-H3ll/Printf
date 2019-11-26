/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:17:48 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:28:22 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		after_dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	int after_width;
	int width;

	j = i;
	width = 0;
	while_after_dot(&width, s, &after_width, &j);
	if (width == 0 && check_for_star(s, i))
	{
		width = va_arg(ap, int);
		j += 1;
	}
	nmbr = wich_conversion(s, i, ap, nmbr);
	if (nmbr.num < 0)
	{
		nmbr.num = -nmbr.num;
		putstr_ret("-");
	}
	if (nmbr.num == 0)
		width += 1;
	while (width-- > nmbr.len)
		putstr_ret("0");
	if (!(nmbr.num == 0))
		just_converting_int_f(s, j, nmbr);
	return (j - i + 3);
}

int		s_after_dot_flag(char *s, int i, va_list ap)
{
	int		j;
	int		width;
	char	*str;
	int		y;

	j = i;
	y = 0;
	width = 0;
	while (ft_isdigit(s[j]))
		j++;
	width = ft_atoi(ft_substr(s, i, j - 1));
	if (width == 0 && check_for_star(s, i))
	{
		width = va_arg(ap, int);
		j += 1;
	}
	str = va_arg(ap, char *);
	s_precision(str, width, y);
	return (j - i + 3);
}

int		left_flag_one(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	int width;
	int z;

	width = 0;
	z = 0;
	z = while_left_flag(s, &i, z);
	j = i;
	while (ft_isdigit(s[j]))
		j++;
	width = ft_atoi(ft_substr(s, i, j - 1));
	if (width == 0 && check_for_star(s, i))
	{
		width = va_arg(ap, int);
		j += 1;
	}
	nmbr = wich_conversion(s, i, ap, nmbr);
	just_converting_int_f(s, j, nmbr);
	if (nmbr.num < 0)
		nmbr.len += 1;
	while (width-- > nmbr.len)
		putstr_ret(" ");
	return (j - i + z + 2);
}

int		left_flag_two(char *s, int i, va_list ap)
{
	int j;
	int width;
	int k;
	int z;

	k = 0;
	z = s_left_flag_helper(&width, s, &i, &j);
	if (width == 0 && check_for_star(s, i))
	{
		width = va_arg(ap, int);
		j += 1;
	}
	if (check_for_convertion(s, j) == 7)
	{
		just_converting_char(s, j, ap, NULL);
		while (width-- > 1)
			putstr_ret(" ");
	}
	else
		s_left_flag_helper_two(s, ap, j, width);
	return (j - i + z + 2);
}

int		zero_flag_one(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	int width;

	j = i;
	width = 0;
	while (ft_isdigit(s[j]))
		j++;
	width = ft_atoi(ft_substr(s, i, j - 1));
	if (width == 0 && check_for_star(s, i))
	{
		width = va_arg(ap, int);
		j += 1;
	}
	nmbr = wich_conversion(s, i, ap, nmbr);
	if (nmbr.num < 0)
	{
		nmbr.num = nmbr.num * (-1);
		nmbr.len += 1;
		putstr_ret("-");
	}
	while (width-- > nmbr.len)
		putstr_ret("0");
	just_converting_int_f(s, j, nmbr);
	return (j - i + 3);
}
