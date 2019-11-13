/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:26:46 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/12 20:55:20 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	char_conversion(char c)
{
	write(1, &c, 1);
}

int		string_conversion(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		number_conversion(char *nmb, int j)
{
	int i;

	i = 0;
	if (j != 0)
		i = 1;
	while (nmb[i] != '\0')
	{
		write(1, &nmb[i], 1);
		i++;
	}
	return (i);
}

static char		return_hex_p(unsigned long	mod_hexa)
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

int		hexa_conversion_p(unsigned long	hexa)
{
	int mod_hexa;
	char *s;
	static char *test;
	static int i;
	static int j;

	if (i == 0)
		if (!(test = (char *)ft_calloc(sizeof(char), (nmbr_count(hexa)) + 1)))
			return (0);
	if (hexa == 0)
	{
		j = i;
		while (i > 0)
		{
			write(1, &test [i - 1], 1);
			i--;
		}
		free(test);
		return (j);
	}
	mod_hexa = hexa % 16;
	if (mod_hexa < 10)
	{
		s = ft_itoa(mod_hexa);
		test[i++] = s[0];
	}
	else if (mod_hexa >= 10)
		test[i++] = return_hex_p(mod_hexa);
	hexa_conversion_p(hexa / 16);
	return (j);
}
