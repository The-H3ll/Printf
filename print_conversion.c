/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:30:50 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:54:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c)
{
	ft_putchar(c);
	return (1);
}

int		print_string(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		s = ft_strdup("(null)");
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		print_hexa(unsigned int i, int z)
{
	int j;

	j = convert_hexa(i, z, 0);
	return (j);
}

int		print_unsigned_int(unsigned int i)
{
	int j;

	j = nmbr_len(i);
	put_nmbr(i);
	return (i);
}

int		print_int(int i)
{
	int j;

	j = nmbr_len(i);
	put_nmbr(i);
	return (i);
}
