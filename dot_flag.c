/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:01:14 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:15:19 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_num		wich_conversion(char *s, int i, va_list ap, t_num nmbr)
{
	int wich;

	wich = check_for_convertion(s, i);
	if (wich == 1)
	{
		nmbr.num = va_arg(ap, int);
		nmbr.len = nmbr_count(nmbr.num);
	}
	else if (wich == 2)
	{
		nmbr.l_num = va_arg(ap, unsigned int);
		nmbr.len = len(nmbr.l_num);
	}
	else if (wich == 3 || wich == 4)
		wich_hexa(&nmbr, ap);
	else if (wich == 5)
		wich_hexa_p(&nmbr, ap);
	else if (wich == 7)
	{
		nmbr.c = va_arg(ap, int);
		nmbr.len = 1;
	}
	return (nmbr);
}

t_num		first_to_use(int width_len, int k, t_num nmbr)
{
	if (width_len < 0)
		width_len = -width_len;
	if (width_len > k && k > nmbr.len && k >= 0)
		to_use_space_zero(k, width_len, &nmbr);
	else if (width_len > k && width_len > nmbr.len && k >= 0)
	{
		if (nmbr.num < 0)
			nmbr.len += 1;
		while (width_len-- > nmbr.len)
			putstr_ret(" ");
	}
	else if (width_len <= k || k < 0)
		to_use_zero(k, width_len, &nmbr);
	return (nmbr);
}

int			after_befor_dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	int how_long_before;
	int width_len;
	int k;

	j = i;
	width_len = 0;
	how_long_before = helper_before_dot(s, &j, ap, &width_len);
	k = j + 1;
	while (ft_isdigit(s[k]))
		k++;
	how_long_before += k - j + 1;
	nmbr.convert_pos = k;
	k = 0;
	k = ft_atoi(ft_substr(s, j + 1, nmbr.convert_pos - 1));
	if (k == 0 && check_for_star(s, j + 1))
	{
		k = va_arg(ap, int);
		nmbr.convert_pos += 1;
		how_long_before += 1;
	}
	nmbr = wich_conversion(s, i, ap, nmbr);
	helper_after_dot(s, k, width_len, nmbr);
	return (how_long_before);
}

int			hyphien_dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int j;
	int how_long_before;
	int width_len;
	int k;

	how_long_before = for_hyphien_flag(s, &i, &j, &width_len);
	if (width_len == 0 && check_for_star(s, i))
	{
		width_len = va_arg(ap, int);
		how_long_before += 1;
		j += 1;
	}
	k = j + 1;
	how_long_before += for_hyphien_flag_two(&k, s, j, &nmbr);
	if (k == 0 && check_for_star(s, j + 1))
	{
		k = va_arg(ap, int);
		nmbr.convert_pos += 1;
		how_long_before += 1;
	}
	nmbr = wich_conversion(s, i, ap, nmbr);
	hyphien_execute(k, width_len, nmbr, s);
	return (how_long_before);
}

int			string_dot_flag(char *s, int i, va_list ap, t_num nmbr)
{
	int		j;
	int		width_len;
	int		how_long_before;
	int		k;
	char	*str;

	j = i;
	width_len = 0;
	how_long_before = string_before_dot(s, ap, &width_len, &j);
	k = j + 1;
	while (ft_isdigit(s[k]))
		k++;
	nmbr.convert_pos = k;
	how_long_before += k - j + 1;
	k = 0;
	k = ft_atoi(ft_substr(s, j + 1, nmbr.convert_pos - 1));
	if (k == 0 && check_for_star(s, j + 1))
	{
		k = va_arg(ap, int);
		how_long_before += 1;
	}
	str = va_arg(ap, char *);
	string_dot_helper(str, width_len, k);
	return (how_long_before);
}
