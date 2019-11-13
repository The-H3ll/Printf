/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:06:12 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/13 00:34:29 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>


int		ft_printf(const char *, ...);
void	char_conversion(char c);
int		flag_zero(char *s, int i, va_list ap, char *str, int len);
int		string_conversion(char *s);
int		number_conversion(char *s, int j);
int		hexa_conversion_min(unsigned int hexa);
int		hexa_conversion_big(unsigned int hexa);
int		hexa_conversion_p(unsigned long hexa);
int		nmbr_count(long hexa);	
int		unsigned_conversion(unsigned long pbe);
int     just_converting_int(char *s, int i, va_list ap, int j, long d, int z);
int		left_flag(char *s, int i, va_list ap, int len, char *str);
int		just_converting_char(char *s, int i, va_list ap, char *str);
#endif
