/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:19:59 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 04:50:55 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (!(str = (void *)malloc(size * count)))
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
