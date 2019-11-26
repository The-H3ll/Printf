/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:19:38 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:41:41 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_neg(t_num *nmbr, int width_len, int k)
{
	if (nmbr->num < 0)
	{
		write(1, "-", 1);
		nmbr->num = -nmbr->num;
		if ((width_len > k && width_len > nmbr->len) || width_len < 0)
			nmbr->len += 1;
	}
}

void			hyphien_execute(int k, int width_len, t_num nmbr, char *s)
{
	int afte_dot;

	afte_dot = k;
	write_neg(&nmbr, width_len, k);
	if (width_len >= afte_dot && k > nmbr.len)
	{
		while (afte_dot-- > nmbr.len)
			putstr_ret("0");
		just_converting_int_f(s, nmbr.convert_pos, nmbr);
		while (width_len-- > k)
			putstr_ret(" ");
	}
	else if (width_len > k && width_len > nmbr.len)
	{
		just_converting_int_f(s, nmbr.convert_pos, nmbr);
		while (width_len-- > nmbr.len)
			putstr_ret(" ");
	}
	else
	{
		nmbr = first_to_use(width_len, k, nmbr);
		just_converting_int_f(s, nmbr.convert_pos, nmbr);
	}
}

int				for_hyphien_flag(char *s, int *i, int *j, int *width_len)
{
	int z;
	int how_long_before;

	z = 0;
	while (s[*i] == '-')
	{
		*i += 1;
		z++;
	}
	*j = *i;
	while (ft_isdigit(s[*j]))
		*j += 1;
	how_long_before = *j + z - *i + 2;
	*width_len = ft_atoi(ft_substr(s, *i, *j - 1));
	return (how_long_before);
}

int				for_hyphien_flag_two(int *k, char *s, int j, t_num *nmbr)
{
	int how_long_before;

	while (ft_isdigit(s[*k]))
		*k += 1;
	how_long_before = *k - j + 1;
	nmbr->convert_pos = *k;
	*k = 0;
	*k = ft_atoi(ft_substr(s, j + 1, nmbr->convert_pos));
	return (how_long_before);
}
