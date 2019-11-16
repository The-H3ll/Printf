/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:52:12 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/16 09:57:41 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// char *s = "labhairi";
	// unsigned int num = 4294967295;
	// int	o = 11111;	
	// int nam = -2147483647;
	int hexa1 = 5698;	

	//int d = 1;
	// int u = 429496;
	//char c = 'p';
	
	printf("%1000.100d\n", hexa1);	
	ft_printf("%1000.10d\n", hexa1);	
	return(0);
}