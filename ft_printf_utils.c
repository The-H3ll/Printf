/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:29:05 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:54:51 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nmbr(long i)
{
	int j;

	j = 0;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i >= 0 && i < 10)
		ft_putchar(i + '0');
	else
	{
		put_nmbr(i / 10);
		j = i % 10;
		ft_putchar(j + '0');
	}
}

int		nmbr_len(long i)
{
	int j;

	j = 0;
	if (i == 0)
		j++;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

int		hexa_convert(int l, int z)
{
	if (z == 0)
	{
		if (l == 10)
			return ('a');
		else if (l == 11)
			return ('b');
		else if (l == 12)
			return ('c');
		else if (l == 13)
			return ('d');
		else if (l == 14)
			return ('e');
		else if (l == 15)
			return ('f');
	}
	else if (z == 1)
		return (big_hexa(l));
	return (0);
}

void	revers_print(char *str, int k)
{
	while (k > 0)
	{
		ft_putchar(str[k - 1]);
		k--;
	}
}

int		convert_hexa(unsigned int i, int z, int y)
{
	int		k;
	char	*str;
	int		l;

	k = 0;
	if (!(str = (char *)ft_calloc(sizeof(char), nmbr_len(i) + 1)))
		return (-1);
	if (i == 0)
		str[k++] = i + '0';
	else
	{
		while (i != 0)
		{
			l = i % 16;
			if (l >= 10)
				str[k++] = hexa_convert(l, z);
			else
				str[k++] = l + '0';
			i = i / 16;
		}
	}
	if (y == 0)
		revers_print(str, k);
	free(str);
	return (k);
}
