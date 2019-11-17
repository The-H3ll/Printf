/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:21:45 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/17 15:36:12 by molabhai         ###   ########.fr       */
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
			i =  string_conversion(va_arg(ap, char *));
		return (2);
	}
	else if (s[i] == 'c')
	{
		char_conversion(va_arg(ap, int));		
		return (2);
	}
	return (0);
}

int		just_converting_int(char *s, int i, va_list ap, int j, long d, int z)
{
	char *number;

	if (s[i] != 'd' && s[i] != 'i' && s[i] != 'x' && s[i] != 'X' && s[i] != 'u' && s[i] != 'p')
		return (0);
	if (s[i] == 'd' || s[i] == 'i')
	{
		if (d != 0)
		{
			number = ft_itoa(d);
			number_conversion(number, z);
		}
		else
		{
			number = ft_itoa(va_arg(ap, int));
			i = number_conversion(number, z);
		}
		if (j == 1)
			return (i);
		return (2);
	}
	else if(s[i] == 'x')
	{
		if (d != 0)
			hexa_conversion_min(d);
		else
			i = hexa_conversion_min(va_arg(ap, int));
		if (j == 1)
			return (i);
		return (2);
	}
	else if (s[i] == 'X')
	{
		if (d != 0)
			hexa_conversion_big(d);
		else
			i = hexa_conversion_big(va_arg(ap, int));
		if (j == 1)
			return (i);
		return (2);
	}
	else if (s[i] == 'u')
	{
		if (d != 0)
			unsigned_conversion(d);
		else
			i = unsigned_conversion(va_arg(ap,  int));
		return (2);
	}
	else if (s[i] == 'p')
	{
		write(1, "0x", 2);
		if (d != 0)
		{
			//write(1, "10", 2);
			hexa_conversion_p(d);
		}
		else
			i =  hexa_conversion_p(va_arg(ap, unsigned long));
		return (2);
	}
	return (0);
}

int		check_for_convertion(char *s, int i)
{
	while (s[i] != 'd' || s[i] != 'u' || s[i] != 'x' || s[i] != 'X' || s[i] != 'i'
	|| s[i] == 's' || s[i] == 'p' || s[i] == 'c')
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
	int	flag_num;
	t_num nmbr;

	flag_num = 0;
	nmbr.only_numbers = 0;
	
	if (check_for_dot(s, i))
		flag_num = dot_flag(s, i, ap, nmbr);
	else if (s[i] == '0')
		flag_num = for_zero_flag(s, i + 1, ap, nmbr);
	else if (s[i] == '-')
	{
		if (s[i + 1] != '0')	
			flag_num = for_left_flag(s, i ,ap, nmbr);
		else
			flag_num += 1;
	}
 	else if (ft_isdigit(s[i]) ||  check_for_star(s, i))
		flag_num = for_digit_flag(s, i, ap, nmbr);
	return (flag_num);
}

int		ft_printf(const char *s, ...)
{
	int i;
	int j;
	int k;
	va_list ap;

	va_start(ap, s);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == '%')
		{
			i = if_flags((char *)s, i + 1, ap) + i;
			k = k + i;
		}
		if (s[i] == '%')
		{
			i = just_converting_char((char *)s, i + 1, ap, NULL) + i;
			i = just_converting_int((char *)s, i + 1, ap, 0, 0, 0) + i;
			k = k + i;
		}
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			i++;
			k++;
		}
	}
	va_end(ap);
	return (k);
}