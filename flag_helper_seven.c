/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_seven.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:17:16 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:37:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mod_helper(char *s, int *j, va_list ap, int *width_len)
{
	int i;
	int width_before;

	i = *j;
	while (ft_isdigit(s[*j]))
		*j += 1;
	*width_len = ft_atoi(s + i);
	width_before = *j - i + 1;
	if (*width_len == 0 && check_for_star(s, i))
	{
		*width_len = va_arg(ap, int);
		width_before += 1;
		*j += 1;
	}
	return (width_before);
}

void	digit_helper(char *s, int j, int width, t_num nmbr)
{
	width = -width;
	if (nmbr.num < 0)
		nmbr.len += 1;
	just_converting_int_f(s, j, nmbr);
	while (width-- > nmbr.len)
		putstr_ret(" ");
}
