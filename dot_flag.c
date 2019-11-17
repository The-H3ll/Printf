/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:01:14 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/17 17:21:22 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    dot_flag_helper_I(char *s, int i, va_list ap, t_num nmbr)
{
    int j;
    int width_between;
    int width_len;
    int after_dot_len;
    int k;

	j = i;
	k = 0;
    after_dot_len = 0;
    while (ft_isdigit(s[j]))
		j++;
	width_between = j - i;
	width_len = ft_atoi(ft_substr(s, i, j - 1));
	if (ft_isdigit(s[j + 1]))
	{
		k = j + 1;
		while (ft_isdigit(s[k]))
			k++;
		after_dot_len = ft_atoi(ft_substr(s, j + 1, k - 1));
		width_between += k - j + 1;
	}
	nmbr = for_dot_flag(s, i, ap, nmbr);
	if (width_len <= after_dot_len)
	{
		if (nmbr.only_numbers < 0)
		{
			write(1, "-", 1);
			nmbr.only_numbers = -nmbr.only_numbers;
		}
		while (after_dot_len > nmbr.len)
		{
			write(1, "0", 1);
			after_dot_len--;
		}
	}
	else if (width_len > after_dot_len &&  width_len > nmbr.len)
	{
		if (nmbr.only_numbers < 0)
			width_len -= 1;
		if (after_dot_len <= nmbr.len)
			after_dot_len = nmbr.len;
		while (width_len > after_dot_len)
		{
			write(1, " ", 1);
			width_len--;
		}
		if (after_dot_len > nmbr.len && nmbr.only_numbers < 0)
		{
			write(1, "-", 1);
			nmbr.only_numbers = -nmbr.only_numbers;
		}
		while(after_dot_len > nmbr.len)
		{
			write(1, "0", 1);
			after_dot_len--;
		}
	}
    just_converting_int(s, k, ap, 0, nmbr.only_numbers, 0);
    return (width_between);
}

int    dot_flag_helper_II(char *s, int i, va_list ap, t_num nmbr)
{
    int k;
    int after_dot_len;
    int width_between;

	k = i + 1;
	after_dot_len = 0;
	while (ft_isdigit(s[k]))
		k++;
	after_dot_len = ft_atoi(ft_substr(s, i + 1, k - 1));
	width_between  = k - i + 1;
	nmbr = for_dot_flag(s, i, ap, nmbr);
	if (nmbr.only_numbers < 0)
	{
		write(1, "-", 1);
		nmbr.only_numbers = -nmbr.only_numbers;
	}
	while (after_dot_len > nmbr.len)
	{
		write(1, "0", 1);
		after_dot_len--;
	}
    just_converting_int(s, k, ap, 0, nmbr.only_numbers, 0);
    return (width_between);
}

int		dot_flag_helper_III(char *s, int i, va_list ap)
{
	int j;
	int width_between;
	char *str;
	int after_dot_len;
	int width_len;
	int k;
	int str_len;

	j = i + 1;
	after_dot_len = 0;
    while (ft_isdigit(s[j]))
		j++;
	width_between = j - i;
	width_len = ft_atoi(ft_substr(s, i, j - 1));
	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (ft_isdigit(s[j + 1]))
	{
		k = j + 1;
		while (ft_isdigit(s[k]))
			k++;
		after_dot_len = ft_atoi(ft_substr(s, j + 1, k - 1));
		width_between += k - j + 1;
		if (str_len > after_dot_len)
			str_len = after_dot_len;
		while (width_len > str_len)
		{
			write(1 , " ", 1);
			width_len--;
		}
		i = 0;
		while (i < str_len)
			write(1, &str[i++], 1);
	}
	else if (!ft_isdigit(s[j + 1]))
	{
		while (width_len > 0)
		{
			write(1, " ", 1);
			width_len--;
		}
		return(width_between + 1);
	}
	return(width_between);
}

int		dot_flag_helper_IIII(char *s, int i, va_list ap)
{
	char *str;
	int str_len;
	int j;
	int width_len;
	int width_between;

	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	j = i + 1;
	while (ft_isdigit(s[j]))
		j++;
	width_between = j - i + 1;
	width_len = ft_atoi(ft_substr(s, i + 1, j - 1));
	if (str_len > width_len)
		str_len = width_len;
	i = 0;
	while (i < str_len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (width_between); 
}