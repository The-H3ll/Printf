/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:33:06 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:55:31 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_for_star(char *s, int i)
{
	if (s[i] == '*')
		return (1);
	return (0);
}

void			flag_checker(char *s, int *i, t_flag *check)
{
	int j;

	*i += 1;
	j = *i;
	if (check_for_dot(s, j) == 1)
	{
		if (s[*i] == '0')
			check->zero = 1;
		check->dot = 1;
	}
	else if (s[*i] == '0')
	{
		check->zero = 1;
		while (s[*i] == '0')
			*i += 1;
	}
	if (s[*i] == '-')
	{
		check->minus = 1;
		while (s[*i] == '-')
			*i += 1;
	}
}

void			take_len(char *s, int *i, t_flag *check, va_list ap)
{
	check->len_before_flag = ft_atoi(s + *i);
	while (ft_isdigit(s[*i]))
		*i += 1;
	if (check->len_before_flag == 0 && check_for_star(s, *i))
	{
		check->len_before_flag = va_arg(ap, int);
		*i += 1;
	}
	if (check->dot == 1)
	{
		if (s[*i] != '%')
			*i += 1;
		check->len_after_flag = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]))
			*i += 1;
		if (check->len_after_flag == 0 && check_for_star(s, *i))
		{
			check->len_after_flag = va_arg(ap, int);
			*i += 1;
		}
	}
}

void			take_conversion(char *s, int i, t_flag *check, va_list ap)
{
	check->wich_conversion = conversion_for_print(s, i - 1);
	if (check->wich_conversion == 0)
		take_char(check, ap);
	else if (check->wich_conversion == 1)
		take_string(check, ap);
	else if (check->wich_conversion == 2 || check->wich_conversion == 3)
		take_hexa(check, ap);
	else if (check->wich_conversion == 4)
		take_unsigned(check, ap);
	else if (check->wich_conversion == 5)
		take_adress(check, ap);
	else if (check->wich_conversion == 6 || check->wich_conversion == 7)
	{
		check->int_conversion = va_arg(ap, int);
		check->nmbr_len = nmbr_len(check->int_conversion);
	}
	else if (check->wich_conversion == 8)
		check->nmbr_len = 1;
}

void			put_flag(char *s, int *i, t_flag *check, va_list ap)
{
	int m;
	int l;

	m = 0;
	l = 0;
	put_it(check, i, s, ap);
	if (check_condition_one(check))
		put_flag_one(check);
	else if (check_condition_two(check))
		check->zero = 0;
	if (check_condition_three(check))
		put_flag_two(check);
	if (check->dot == 1)
		dot_flag(check, &m, &l);
	if (check->zero == 0 && check->minus == 0)
		no_zero_no_minus(check, m, l);
	if (check_condition_four(check))
		ft_putchar('0');
	if (check->int_conversion < 0 && check->zero == 1)
		put_flag_three(check);
	if (check->zero == 1)
		flag_zero(check, l);
	if (check->minus == 1)
		minus_flag(check, m, l);
	*i += 1;
}
