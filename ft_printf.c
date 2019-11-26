/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:21:45 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:59:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int		just_converting_char(char *s, int i, va_list ap, char *str)
{
	if (s[i] != 's' && s[i] != 'c')
		return (0);
	if (s[i] == 's')
	{
		if (str != NULL)
			i = string_conversion(str);
		else
			i = string_conversion(va_arg(ap, char *));
		return (2);
	}
	else if (s[i] == 'c')
	{
		char_conversion(va_arg(ap, int));
		return (2);
	}
	return (0);
}

int		just_converting_int(char *s, int i, va_list ap)
{
	char *number;

	if (s[i] == 'd' || s[i] == 'i')
	{
		number = ft_itoa(va_arg(ap, int));
		number_conversion(number);
	}
	else if (s[i] == 'x')
		hexa_conversion_min(va_arg(ap, int));
	else if (s[i] == 'X')
		hexa_conversion_big(va_arg(ap, unsigned int));
	else if (s[i] == 'u')
		unsigned_conversion(va_arg(ap, unsigned int));
	else if (s[i] == 'p')
	{
		putchar_ret('0');
		putchar_ret('x');
		hexa_conversion_p(va_arg(ap, unsigned long));
	}
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'x'
	|| s[i] == 'X' || s[i] == 'u' || s[i] == 'p')
		return (2);
	return (0);
}

int		check_for_convertion(char *s, int i)
{
	while (s[i] != 'd' || s[i] != 'u' || s[i] != 'x' ||
	s[i] != 'X' || s[i] != 'i' || s[i] != 's' || s[i] != 'p' || s[i] != 'c')
	{
		if (s[i] == 'd' || s[i] == 'i')
			return (1);
		else if (s[i] == 'u')
			return (2);
		else if (s[i] == 'x')
			return (3);
		else if (s[i] == 'X')
			return (4);
		else if (s[i] == 'p')
			return (5);
		else if (s[i] == 's')
			return (6);
		else if (s[i] == 'c')
			return (7);
		i++;
	}
	return (0);
}

int		if_flags(char *s, int i, va_list ap)
{
	int		flag_num;
	t_num	nmbr;

	flag_num = 0;
	nmbr.only_numbers = 0;
	if (check_for_dot(s, i) == 1)
		flag_num = dot_flag(s, i, ap, nmbr);
	else if (s[i] == '-')
		flag_num = left_flag(s, i, ap, nmbr);
	else if (s[i] == '0')
		flag_num = zero_flag(s, i, ap, nmbr);
	else if (ft_isdigit(s[i]) || check_for_star(s, i))
		flag_num = digit_flag(s, i, ap, nmbr);
	return (flag_num);
}

int		ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			i = if_flags((char *)s, i + 1, ap) + i;
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				i = putchar_ret('%') + i + 1;
			i = just_converting_char((char *)s, i + 1, ap, NULL) + i;
			i = just_converting_int((char *)s, i + 1, ap) + i;
		}
		if (s[i] != '%' && s[i] != '\0')
		{
			putchar_ret(s[i]);
			i++;
		}
	}
	va_end(ap);
	i = putstr_ret(NULL) + putchar_ret(0);
	return (i);
}
