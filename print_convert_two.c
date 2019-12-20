/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_convert_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:40:59 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:59:37 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex_adress(unsigned long long i, int j)
{
	char	*str;
	int		k;
	int		l;

	str = (char *)ft_calloc(sizeof(char), nmbr_len(i));
	k = 0;
	if (i == 0)
		str[k++] = i + '0';
	while (i != 0)
	{
		l = i % 16;
		if (l >= 10)
			str[k++] = hexa_convert(l, 0);
		else
			str[k++] = l + '0';
		i = i / 16;
	}
	if (j == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		revers_print(str, k);
	}
	free(str);
	return (k);
}

int		print_mod(void)
{
	ft_putchar('%');
	return (0);
}
