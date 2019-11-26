/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:51:35 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:33:42 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_precision(char *str, int width, int y)
{
	int o;

	if (str == NULL)
	{
		o = 6;
		str = ft_strdup("(null)");
	}
	else
		o = (int)ft_strlen(str);
	if (width <= o)
	{
		if (width < 0)
			while (y < o)
				putchar_ret(str[y++]);
		else
			while (y < width)
				putchar_ret(str[y++]);
	}
	else
	{
		while (y < o)
			putchar_ret(str[y++]);
	}
}

int		s_left_flag_helper(int *width, char *s, int *i, int *j)
{
	int z;

	z = 0;
	while (s[*i] == '-')
	{
		*i += 1;
		z++;
	}
	*j = *i;
	while (ft_isdigit(s[*j]))
		*j += 1;
	*width = ft_atoi(ft_substr(s, *i, *j - 1));
	return (z);
}

void	s_left_flag_helper_two(char *s, va_list ap, int j, int width)
{
	int		k;
	char	*str;

	k = 0;
	str = va_arg(ap, char *);
	if (str != NULL)
	{
		just_converting_char(s, j, ap, str);
		while (width-- > (int)ft_strlen(str))
			putstr_ret(" ");
	}
	else
	{
		k = 6;
		putstr_ret("(null)");
		while (width-- > k)
			putchar_ret(' ');
	}
}

int		while_left_flag(char *s, int *i, int z)
{
	while (s[*i] == '-')
	{
		z++;
		*i += 1;
	}
	return (z);
}

void	while_after_dot(int *width, char *s, int *after_width, int *j)
{
	int i;

	i = *j;
	while (ft_isdigit(s[*j]))
		*j += 1;
	*after_width = *j - i;
	*width = ft_atoi(ft_substr(s, i, *j - 1));
}
