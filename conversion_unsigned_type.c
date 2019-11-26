/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_unsigned_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:44:46 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 18:48:02 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int		ft_putnbr(long n)
{
	long		i;
	static long j;

	i = n;
	j = 0;
	if (i < 0)
	{
		ft_putchar('-');
		j += 1;
		i = i * (-1);
	}
	if (i >= 0 && i <= 9)
	{
		ft_putchar(i + '0');
		j += 1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		i = i % 10;
		ft_putchar(i + '0');
		j += 1;
	}
	return (j);
}

int				unsigned_conversion(unsigned long pbe)
{
	unsigned int	i;
	char			*convert;
	unsigned long	sum;

	i = 0;
	sum = 4294967295;
	convert = ul_itoi(pbe);
	if (convert[0] == '-')
	{
		sum = sum + pbe + 1;
		i = ft_putnbr(sum);
		return (i);
	}
	while (convert[i] != '\0')
	{
		putchar_ret(convert[i]);
		i++;
	}
	return (i);
}
