/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag_helper_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:33 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:18:46 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		helper_before_dot(char *s, int *j, va_list ap, int *width_len)
{
	int i;
	int how_long_before;

	i = *j;
	while (ft_isdigit(s[*j]) != 0)
		*j += 1;
	how_long_before = *j - i + 1;
	*width_len = ft_atoi(ft_substr(s, i, *j - 1));
	if (*width_len == 0 && (check_for_star(s, i) || check_for_star(s, i + 1)))
	{
		*width_len = va_arg(ap, int);
		how_long_before += 1;
		*j += 1;
	}
	return (how_long_before);
}

void	helper_after_dot(char *s, int k, int width_len, t_num nmbr)
{
	if (nmbr.num == 0)
	{
		k += 1;
		width_len += 1;
	}
	if (width_len < 0)
		just_converting_int_f(s, nmbr.convert_pos, nmbr);
	nmbr = first_to_use(width_len, k, nmbr);
	if (width_len >= 0 && (!(nmbr.num == 0)))
		just_converting_int_f(s, nmbr.convert_pos, nmbr);
}

void	to_use_space_zero(int k, int width_len, t_num *nmbr)
{
	if (nmbr->num < 0)
	{
		k += 1;
		nmbr->len += 1;
	}
	while (width_len-- > k)
		putstr_ret(" ");
	if (nmbr->num < 0)
	{
		putstr_ret("-");
		nmbr->num = -nmbr->num;
	}
	while (k-- > nmbr->len)
		putstr_ret("0");
}

void	to_use_zero(int k, int width_len, t_num *nmbr)
{
	if (k < 0)
	{
		k = width_len;
		nmbr->len += 1;
	}
	if (k > nmbr->len)
	{
		if (nmbr->num < 0)
		{
			nmbr->num = -nmbr->num;
			putstr_ret("-");
		}
		while (k-- > nmbr->len)
			putstr_ret("0");
	}
}

void	wich_hexa(t_num *nmbr, va_list ap)
{
	nmbr->u_num = va_arg(ap, unsigned int);
	nmbr->len = len(nmbr->u_num);
	if (nmbr->len == 10)
		nmbr->len -= 2;
	else
		nmbr->len -= 1;
}
