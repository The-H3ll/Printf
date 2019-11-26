/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:28:47 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 22:07:41 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_modulo(char *s, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == 'd' || s[i] == 'u' || s[i] == 'x' ||
				s[i] == 'X' || s[i] == 'i' || s[i] == 's' || s[i] == 'p'
				|| s[i] == 'c')
			return (0);
		else if (s[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		zero_flag_mod(char *s, int i, va_list ap)
{
	int j;
	int width_len;

	j = i;
	while (ft_isdigit(s[j]))
		j++;
	width_len = ft_atoi(ft_substr(s, i, j - 1));
	if (width_len == 0 && check_for_star(s, i))
	{
		width_len = va_arg(ap, int);
		j++;
	}
	while (width_len-- > 1)
		putchar_ret('0');
	putchar_ret('%');
	return (j - i + 2);
}

int		digit_flag_mod(char *s, int i, va_list ap)
{
	int j;
	int width_len;

	j = i;
	while (ft_isdigit(s[j]))
		j++;
	width_len = ft_atoi(ft_substr(s, i, j - 1));
	if (width_len == 0 && check_for_star(s, i))
	{
		width_len = va_arg(ap, int);
		j++;
	}
	while (width_len-- > 1)
		putchar_ret(' ');
	putchar_ret('%');
	return (j - i + 2);
}

int		left_flag_mod(char *s, int i, va_list ap)
{
	int j;
	int width_len;

	j = i;
	while (ft_isdigit(s[j]))
		j++;
	width_len = ft_atoi(ft_substr(s, i, j - 1));
	if (width_len == 0 && check_for_star(s, i))
	{
		width_len = va_arg(ap, int);
		j++;
	}
	putchar_ret('%');
	while (width_len-- > 1)
		putchar_ret(' ');
	return (j - i + 3);
}

int		dot_flag_mod(char *s, int i, va_list ap)
{
	int j;
	int width_len;
	int width_before;
	int width_len_after;

	j = i;
	width_before = mod_helper(s, &j, ap, &width_len);
	width_len_after = j + 1;
	if (ft_isdigit(s[width_len_after]) || check_for_star(s, j + 1))
	{
		while (ft_isdigit(s[width_len_after]))
			width_len_after++;
		width_before += width_len_after - j;
		if (width_len_after == 0 || check_for_star(s, j + 1))
		{
			width_len_after = va_arg(ap, int);
			width_before += 1;
		}
	}
	while (width_len-- > 1)
		putchar_ret(' ');
	putchar_ret('%');
	return (width_before + 1);
}
