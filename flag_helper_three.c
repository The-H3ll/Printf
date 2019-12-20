/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 03:29:48 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:29:39 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_unsigned(t_flag *check, va_list ap)
{
	check->unsigned_conversion = va_arg(ap, unsigned int);
	check->nmbr_len = nmbr_len(check->unsigned_conversion);
}

void	take_adress(t_flag *check, va_list ap)
{
	check->adress_conversion = va_arg(ap, unsigned long long);
	check->nmbr_len = print_hex_adress(check->adress_conversion, 1) + 2;
}

void	put_flag_one(t_flag *check)
{
	check->len_after_flag = check->len_before_flag;
	if (check->int_conversion < 0)
		check->nmbr_len += 1;
}

void	put_flag_two(t_flag *check)
{
	check->zero = 0;
	check->minus = 1;
	check->len_before_flag = -check->len_before_flag;
}

void	put_flag_three(t_flag *check)
{
	if (!(check->int_conversion == -2147483648))
		ft_putchar('-');
	if (check->dot == 0)
		check->nmbr_len += 1;
	check->int_conversion = -check->int_conversion;
}
