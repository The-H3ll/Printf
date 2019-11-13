/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:52:12 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/13 03:10:31 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	//char *s = "labhairi";
	unsigned int nam = 4294967295;
	//int	o = 11111;	
	// int u = 429496;
//	char c = 'p';
	//printf("tes-%2c with numbers-%010X with strings -%20p \n", c, o, s);
	
	printf("test with flags [-] unsigned int %-1u\n", nam);
	ft_printf("test with flags [-] unsigned int %-1u\n", nam);
	
	return(0);
}