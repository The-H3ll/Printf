/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:24:04 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:51:12 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i != len)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}
