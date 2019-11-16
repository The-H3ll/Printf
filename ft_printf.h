/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:06:12 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/16 06:50:12 by molabhai         ###   ########.fr       */
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

typedef     struct      s_numbers
{
    int num;
    long only_numbers;
    unsigned int u_num;
    long  l_num;
    unsigned long ul_num;
    int len;
    int dot_flag;
}                       t_num;

int     check_for_star(char *s, int i);
int		ft_printf(const char *, ...);
void	char_conversion(char c);
int		flag_zero(char *s, int i, va_list ap, char *str, t_num len);
int		string_conversion(char *s);
int		number_conversion(char *s, int j);
int		hexa_conversion_min(unsigned int hexa);
int		hexa_conversion_big(unsigned int hexa);
int		hexa_conversion_p(unsigned long hexa);
int		nmbr_count(long hexa);	
int		unsigned_conversion(unsigned long pbe);
int     just_converting_int(char *s, int i, va_list ap, int j, long d, int z);
int		left_flag(char *s, int i, va_list ap, t_num len, char *str);
int		just_converting_char(char *s, int i, va_list ap, char *str);
char    *ul_itoi(unsigned long number);
int      width_flags(char *s, int i, va_list ap, t_num nmbr, char *str);
int     check_for_dot(char *s, int i);
int     for_digit_flag(char *s, int i, va_list ap, t_num number);
int     for_left_flag(char *s, int i, va_list ap, t_num nmbr);
int		check_for_convertion(char *s, int i);
int     for_zero_flag(char *s, int i, va_list ap, t_num num);
int		dot_flag(char *s, int i, va_list ap, t_num nmbr);

#endif
