/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:39:56 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:53:41 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_i;

static	void	all_in(t_flag check)
{
	if (check.adress_conversion == 0 && check.wich_conversion == 5 &&
			check.dot == 1 && check.minus == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	if (check.int_conversion == 0 && check.unsigned_conversion == 0 &&
			check.hexa_conversion == 0 && check.dot == 1 &&
			check.wich_conversion != 0 && check.adress_conversion == 0
			&& check.wich_conversion != 8)
		check.minus = 1;
	if (check.minus == 0)
		print_conversion(&check);
}

int				conversion_for_print(char *s, int i)
{
	int		j;
	char	*str;
	int		k;

	j = i + 1;
	str = "csxXupdi%";
	while (s[j])
	{
		k = 0;
		while (str[k])
		{
			if (str[k] == s[j])
				return (k);
			k++;
		}
		j++;
	}
	return (0);
}

int				print_conversion(t_flag *check)
{
	int k;

	k = 0;
	if (check->wich_conversion == 0)
		k = print_char(check->char_conversion);
	else if (check->wich_conversion == 1)
		k = print_string(check->str_conversion);
	else if (check->wich_conversion == 2)
		k = print_hexa(check->hexa_conversion, 0);
	else if (check->wich_conversion == 3)
		k = print_hexa(check->hexa_conversion, 1);
	else if (check->wich_conversion == 4)
		k = print_unsigned_int(check->unsigned_conversion);
	else if (check->wich_conversion == 5)
		k = print_hex_adress(check->adress_conversion, 0);
	else if (check->wich_conversion == 6 || check->wich_conversion == 7)
		k = print_int(check->int_conversion);
	else if (check->wich_conversion == 8)
		k = print_mod();
	return (0);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
	g_i++;
}

int				ft_printf(const char *s, ...)
{
	va_list ap;
	int		i;
	t_flag	check;

	i = 0;
	g_i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_memset(&check, 0, sizeof(t_flag ));
			put_flag((char *)s, &i, &check, ap);
			all_in(check);
		}
		if (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(ap);
	return (g_i);
}
