/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:08:51 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 22:09:30 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int width_between;

	width_between = 0;
	if (check_for_modulo(s, i))
		width_between = dot_flag_mod(s, i, ap);
	else if (s[i] != '.' && check_for_convertion(s, i) == 6)
		width_between = string_dot_flag(s, i, ap, nmbr);
	else if ((ft_isdigit(s[i]) || check_for_star(s, i)))
		width_between = after_befor_dot_flag(s, i, ap, nmbr);
	else if (check_for_hyphien(s, i))
		width_between = hyphien_dot_flag(s, i + 1, ap, nmbr);
	else if (s[i] == '.' && check_for_convertion(s, i) == 6)
		width_between = s_after_dot_flag(s, i + 1, ap);
	else if (s[i] == '.')
		width_between = after_dot_flag(s, i + 1, ap, nmbr);
	return (width_between);
}

int		left_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int	width_between;

	width_between = 0;
	if (check_for_modulo(s, i))
		width_between = left_flag_mod(s, i, ap);
	else if (check_for_convertion(s, i) == 6 || check_for_convertion(s, i) == 7)
		width_between = left_flag_two(s, i, ap);
	else
		width_between = left_flag_one(s, i, ap, nmbr);
	return (width_between);
}

int		zero_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int width_between;

	width_between = 0;
	if (check_for_modulo(s, i))
		width_between = zero_flag_mod(s, i + 1, ap);
	else
		width_between = zero_flag_one(s, i + 1, ap, nmbr);
	return (width_between);
}

int		digit_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int width_between;

	if (check_for_modulo(s, i))
		width_between = digit_flag_mod(s, i, ap);
	else if (check_for_convertion(s, i) == 6 || check_for_convertion(s, i) == 7)
		width_between = digit_flag_two(s, i, ap, nmbr);
	else
		width_between = digit_flag_one(s, i, ap, nmbr);
	return (width_between);
}
