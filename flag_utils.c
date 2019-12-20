/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:09:22 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 03:16:40 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_y = 0;
char *g_s = NULL;
int g_k;

static void		string_dot_flag(t_flag *check, int *m, int *l)
{
	str_or_null(check, &g_y, l, &g_s);
	g_k = *l;
	if (check->minus == 0)
	{
		while (*m > g_k)
		{
			ft_putchar(' ');
			*m -= 1;
		}
	}
	while (*l > 0)
	{
		ft_putchar(g_s[g_y]);
		*l -= 1;
		g_y++;
	}
	if (check->minus == 0 || (check->minus == 1 && *m < 0))
		*m = -*m;
	while (*m > g_k)
	{
		ft_putchar(' ');
		*m -= 1;
	}
	check->minus = 0;
	check->zero = 0;
}

void			dot_flag(t_flag *check, int *m, int *l)
{
	*m = check->len_before_flag;
	*l = check->len_after_flag;
	if (check->wich_conversion == 1)
		string_dot_flag(check, m, l);
	else if (*m == *l && check->wich_conversion != 8)
		before_equal_after(check);
	else if (*m < *l && check->wich_conversion != 8)
		before_less_after(check);
	if (check->minus == 1 && check->wich_conversion != 8)
		check_minus_dot(m, l, check);
	if ((check->dot == 1 && check->int_conversion == 0 &&
			check->unsigned_conversion == 0 && check->hexa_conversion == 0 &&
			check->wich_conversion != 0 && check->wich_conversion != 1 &&
			check->len_after_flag >= 0 && check->wich_conversion != 5 &&
			check->wich_conversion != 8))
		check->nmbr_len = 0;
	if (check->wich_conversion == 5 && check->adress_conversion == 0 &&
			(*m > 0 || *m < 0))
		check->nmbr_len -= 1;
	if (check->int_conversion < 0)
		*m -= 1;
	if (check->wich_conversion == 5 && *m < 0)
		check->minus = 1;
}

void			minus_flag(t_flag *check, int m, int l)
{
	if (check->dot == 1)
	{
		check->len_before_flag = m;
		if (l > check->nmbr_len && check->wich_conversion != 8)
			check->nmbr_len = l;
	}
	if (!(check->dot == 1 && check->int_conversion == 0 &&
			check->unsigned_conversion == 0 && check->hexa_conversion == 0 &&
			check->wich_conversion != 0 && check->len_after_flag >= 0 &&
			check->wich_conversion != 8))
		print_conversion(check);
	else if (check->wich_conversion == 5 && check->adress_conversion == 0 &&
			check->dot == 1)
		put_for_dot();
	else if (check->wich_conversion == 5 && check->dot == 1)
		print_conversion(check);
	if (check->len_before_flag < 0)
		check->len_before_flag = -check->len_before_flag;
	if (check->int_conversion < 0)
		check->nmbr_len += 1;
	while (check->len_before_flag-- > check->nmbr_len)
		ft_putchar(' ');
	if (check->wich_conversion == 5 && check->adress_conversion == 0)
		check->len_before_flag = m;
}

void			no_zero_no_minus(t_flag *check, int m, int l)
{
	if (check->dot == 1)
	{
		check->len_before_flag = m;
		if (l > check->nmbr_len && check->wich_conversion != 8)
		{
			while (check->len_before_flag-- > l)
				ft_putchar(' ');
			check->zero = 1;
		}
		else
			while (check->len_before_flag-- > check->nmbr_len)
				ft_putchar(' ');
	}
	else
	{
		if (check->int_conversion < 0)
			check->nmbr_len += 1;
		while (check->len_before_flag-- > check->nmbr_len)
			ft_putchar(' ');
	}
}

void			flag_zero(t_flag *check, int l)
{
	if (check->dot == 1)
		while (l-- > check->nmbr_len)
			ft_putchar('0');
	else
		while (check->len_before_flag-- > check->nmbr_len)
			ft_putchar('0');
}
