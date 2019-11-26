/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag_helper_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:57:24 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:19:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_space_after(int k, int width_len, char *str, int j)
{
	int i;

	i = 0;
	while (i < k)
		putchar_ret(str[i++]);
	if (width_len < 0)
		width_len = -width_len;
	if (k < j)
		while (width_len-- > k)
			putchar_ret(' ');
	else
		while (width_len-- > j)
			putchar_ret(' ');
}

static void		put_space_before(int k, int width_len, char *str, int j)
{
	int i;

	if (k < j)
		while (width_len-- > k)
			putstr_ret(" ");
	else
		while (width_len-- > j)
			putstr_ret(" ");
	i = 0;
	while (i < k)
		putchar_ret(str[i++]);
}

void			string_dot_helper(char *str, int width_len, int k)
{
	int j;

	if (str == NULL)
	{
		j = 6;
		str = ft_strdup("(null)");
	}
	else
		j = (int)ft_strlen(str);
	if (k >= j)
		k = j;
	if (width_len > k)
		put_space_before(k, width_len, str, j);
	else if (width_len <= j)
		put_space_after(k, width_len, str, j);
}

int				string_before_dot(char *s, va_list ap, int *width_len, int *j)
{
	int how_long_before;
	int i;

	i = *j;
	while (ft_isdigit(s[*j]))
		*j += 1;
	how_long_before = *j - i + 1;
	*width_len = ft_atoi(ft_substr(s, i, *j - 1));
	if (*width_len == 0 && check_for_star(s, i))
	{
		*width_len = va_arg(ap, int);
		how_long_before += 1;
		*j += 1;
	}
	return (how_long_before);
}

void			wich_hexa_p(t_num *nmbr, va_list ap)
{
	nmbr->ul_num = va_arg(ap, unsigned long);
	nmbr->len = len(nmbr->ul_num);
	if (nmbr->ul_num == 0)
		nmbr->len += 2;
	else
		nmbr->len += 1;
}
