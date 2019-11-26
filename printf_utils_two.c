/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:56:07 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 22:09:50 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putchar_ret(char c)
{
	static int j = 0;

	if (c == 0)
		return (j);
	write(1, &c, 1);
	j++;
	return (1);
}

int		check_for_hyphien(char *s, int i)
{
	if (s[i] == '-')
		return (1);
	return (0);
}

int		putstr_ret(char *s)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (s == NULL)
		return (j);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		j++;
	}
	return (i);
}

int		digit_flag_one(char *s, int i, va_list ap, t_num nmbr)
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
	if (width < 0)
		digit_helper(s, j, width, nmbr);
	else
	{
		if (nmbr.num < 0)
			nmbr.len += 1;
		while (width-- > nmbr.len)
			putstr_ret(" ");
		just_converting_int_f(s, j, nmbr);
	}
	return (j - i + 2);
}

int		digit_flag_two(char *s, int i, va_list ap, t_num nmbr)
{
	int		j;
	int		width;
	char	*str;

	j = i;
	while_for_digit_flag(s, &j, &width);
	nmbr = wich_conversion(s, i, ap, nmbr);
	star_digit_flag(&width, s, ap, &j);
	if (check_for_convertion(s, i) == 6)
	{
		str = va_arg(ap, char *);
		if (str != NULL)
		{
			null_digit_flag(str, width);
			just_converting_char(s, j, ap, str);
		}
		else
			for_digit_flag(width);
	}
	else
		for_digit_flag_two(width, nmbr);
	return (j - i + 2);
}
