/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 03:55:29 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 05:32:16 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_condition_one(t_flag *check)
{
	if (check->dot == 1 && check->zero == 1 && check->len_before_flag > 0 &&
			check->len_after_flag < 0)
		return (1);
	return (0);
}

int		check_condition_two(t_flag *check)
{
	if (check->dot == 1 && check->zero == 1 && check->len_before_flag >= 0
			&& check->len_after_flag >= 0)
		return (1);
	return (0);
}

int		check_condition_three(t_flag *check)
{
	if (check->len_before_flag < 0 && (!(check->dot == 1 &&
					(check->wich_conversion == 1 ||
					check->wich_conversion == 5))))
		return (1);
	return (0);
}

int		check_condition_four(t_flag *check)
{
	if ((check->len_after_flag < 0 && check->minus == 0 &&
				check->int_conversion == 0 && check->unsigned_conversion == 0
				&& check->hexa_conversion == 0 && check->wich_conversion != 1
				&& check->wich_conversion != 8) || (check->dot == 1 &&
					check->minus == 0 &&
				check->len_after_flag < 0 && check->len_before_flag == 0 &&
				check->int_conversion == 0 && check->hexa_conversion == 0 &&
				check->unsigned_conversion == 0 && check->wich_conversion != 8
				&& check->wich_conversion != 1 && check->wich_conversion != 0))
		return (1);
	return (0);
}

void	put_it(t_flag *check, int *i, char *s, va_list ap)
{
	flag_checker(s, i, check);
	take_len(s, i, check, ap);
	take_conversion(s, *i, check, ap);
}
