/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:35:38 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:56:30 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		big_hexa(int l)
{
	if (l == 10)
		return ('A');
	else if (l == 11)
		return ('B');
	else if (l == 12)
		return ('C');
	else if (l == 13)
		return ('D');
	else if (l == 14)
		return ('E');
	else if (l == 15)
		return ('F');
	return (0);
}

int		check_for_dot(char *s, int i)
{
	while (s[i] != 's' && s[i] != 'c' && s[i] != 'x' && s[i] != 'X' &&
			s[i] != 'p' && s[i] != 'd' && s[i] != 'p' && s[i] != '\0')
	{
		if (s[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	str_or_null(t_flag *check, int *i, int *l, char **s)
{
	if (check->str_conversion == NULL)
		*i = 6;
	else
		*i = ft_strlen(check->str_conversion);
	if (*l < 0 || *l >= *i)
		*l = *i;
	if (check->str_conversion == NULL)
		*s = ft_strdup("(null)");
	else
		*s = ft_strdup(check->str_conversion);
	*i = 0;
}

void	before_equal_after(t_flag *check)
{
	if (!(check->wich_conversion == 5))
		check->zero = 1;
	if (check->int_conversion == 0 && check->unsigned_conversion == 0 &&
			check->hexa_conversion == 0)
		check->nmbr_len = 0;
}

void	before_less_after(t_flag *check)
{
	check->zero = 1;
	if (check->int_conversion == 0 && check->unsigned_conversion == 0 &&
			check->hexa_conversion == 0 && check->wich_conversion != 5)
		check->nmbr_len = 0;
}
