/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper_six.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:56:53 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 21:41:11 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_digit_flag(int width)
{
	int k;

	k = 6;
	while (width-- > k)
		putstr_ret(" ");
	putstr_ret("(null)");
}

void	for_digit_flag_two(int width, t_num nmbr)
{
	while (width-- > nmbr.len)
		putstr_ret(" ");
	write(1, &nmbr.c, 1);
}

void	while_for_digit_flag(char *s, int *j, int *width)
{
	int i;

	i = *j;
	*width = 0;
	while (ft_isdigit(s[*j]))
		*j += 1;
	*width = ft_atoi(ft_substr(s, i, *j - 1));
}

void	null_digit_flag(char *str, int width)
{
	while (width-- > (int)ft_strlen(str))
		putstr_ret(" ");
}

void	star_digit_flag(int *width, char *s, va_list ap, int *j)
{
	int i;

	i = *j;
	if (*width == 0 && check_for_star(s, i))
	{
		*width = va_arg(ap, int);
		*j += 1;
	}
}
