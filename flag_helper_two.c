/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 03:08:27 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:57:06 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_dot(int *m, int *l, t_flag *check)
{
	if (*m == *l)
		check->minus = 0;
	else if (*m < *l)
		check->minus = 0;
	check->zero = 1;
}

void	put_for_dot(void)
{
	ft_putchar('0');
	ft_putchar('x');
}

void	take_char(t_flag *check, va_list ap)
{
	check->char_conversion = va_arg(ap, int);
	check->nmbr_len = 1;
}

void	take_string(t_flag *check, va_list ap)
{
	check->str_conversion = va_arg(ap, char *);
	if (check->str_conversion == NULL)
		check->nmbr_len = 6;
	else
		check->nmbr_len = ft_strlen(check->str_conversion);
}

void	take_hexa(t_flag *check, va_list ap)
{
	check->hexa_conversion = va_arg(ap, unsigned int);
	check->nmbr_len = convert_hexa(check->hexa_conversion, 0, 1);
}
