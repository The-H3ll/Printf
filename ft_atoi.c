/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:16:19 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:50:28 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		result(char *str, int neg, int i, int res)
{
	int carac;

	while (str[i] >= '0' && str[i] <= '9')
	{
		carac = str[i] - '0';
		res = carac % 10 + res * 10;
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			if (neg != 0)
				res = -res;
			return (res);
		}
		i++;
	}
	if (neg != 0)
		res = -res;
	return (res);
}

int		go_next(char str)
{
	if ((str >= 9 && str <= 13) || str == ' ')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	long		i;
	int			res;
	int			neg;

	i = 0;
	res = 0;
	neg = 0;
	while (go_next(str[i]) != '\0')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = result((char *)str, neg, i, res);
	return (res);
}
