/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:26:46 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:45:59 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			char_conversion(char c)
{
	putchar_ret(c);
}

int				string_conversion(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		putstr_ret("(null)");
	i = putstr_ret(s);
	return (i);
}

int				number_conversion(char *nmb)
{
	int i;

	i = 0;
	i = putstr_ret(nmb);
	return (i);
}

static char		return_hex_p(unsigned long mod_hexa)
{
	if (mod_hexa == 10)
		return ('a');
	else if (mod_hexa == 11)
		return ('b');
	else if (mod_hexa == 12)
		return ('c');
	else if (mod_hexa == 13)
		return ('d');
	else if (mod_hexa == 14)
		return ('e');
	else if (mod_hexa == 15)
		return ('f');
	return (0);
}

void			hexa_conversion_p(unsigned long hexa)
{
	int			mod_hexa;
	static char *test;
	static int	i = 0;

	if (i == 0)
		test = (char *)ft_calloc(sizeof(char), (nmbr_count(hexa)) + 1);
	if (hexa == 0 && i != 0)
	{
		while (i > 0)
		{
			putchar_ret(test[i - 1]);
			i--;
		}
		free(test);
		return ;
	}
	mod_hexa = hexa % 16;
	if (mod_hexa < 10)
		test[i++] = mod_hexa + '0';
	else
		test[i++] = return_hex_p(mod_hexa);
	hexa_conversion_p(hexa / 16);
}
