/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_for_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:32:24 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:49:17 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		for_int_convert(t_num d)
{
	char *number;

	if (d.num || d.num == 0)
	{
		number = ft_itoa(d.num);
		number_conversion(number);
	}
}

int				just_converting_int_f(char *s, int i, t_num d)
{
	if (s[i] == 'd' || s[i] == 'i')
		for_int_convert(d);
	else if (s[i] == 'x')
		hexa_conversion_min(d.u_num);
	else if (s[i] == 'X')
		hexa_conversion_big(d.u_num);
	else if (s[i] == 'u')
		unsigned_conversion(d.l_num);
	else if (s[i] == 'p')
	{
		putstr_ret("0x");
		hexa_conversion_p(d.ul_num);
	}
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'x'
			|| s[i] == 'X' || s[i] == 'u' || s[i] == 'p')
		return (2);
	return (0);
}
