/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:22:03 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 20:53:25 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				nmbr_count(long hexa)
{
	long i;

	i = 0;
	if (hexa == 0)
		i++;
	while (hexa != 0)
	{
		hexa = hexa / 10;
		i++;
	}
	return (i);
}

static char		return_hex_min(int mod_hexa)
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

static char		return_hex_big(int mod_hexa)
{
	if (mod_hexa == 10)
		return ('A');
	else if (mod_hexa == 11)
		return ('B');
	else if (mod_hexa == 12)
		return ('C');
	else if (mod_hexa == 13)
		return ('D');
	else if (mod_hexa == 14)
		return ('E');
	else if (mod_hexa == 15)
		return ('F');
	return (0);
}

void			hexa_conversion_min(unsigned int hexa)
{
	int			mod_hexa;
	static char *test;
	static int	i = 0;

	if (i == 0)
		test = (char *)ft_calloc(sizeof(char), nmbr_count(hexa));
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
	else if (mod_hexa >= 10)
		test[i++] = return_hex_min(mod_hexa);
	hexa_conversion_min(hexa / 16);
}

void			hexa_conversion_big(unsigned int hexa)
{
	int			mod_hexa;
	static char *test;
	static int	i = 0;

	if (i == 0)
		test = (char *)ft_calloc(sizeof(char), nmbr_count(hexa));
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
	else if (mod_hexa >= 10)
		test[i++] = return_hex_big(mod_hexa);
	hexa_conversion_big(hexa / 16);
}
