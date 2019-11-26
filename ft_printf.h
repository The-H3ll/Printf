/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:06:12 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 20:41:06 by molabhai         ###   ########.fr       */
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
    long num;
    long only_numbers;
    unsigned int u_num;
    long  l_num;
    unsigned long ul_num;
    int len;
    int dot_flag;
    int convert_pos;
    int string_len;
    char c;
}                       t_num;

int     check_for_star(char *s, int i);
int		ft_printf(const char *, ...);
void	char_conversion(char c);
int		string_conversion(char *s);
int		number_conversion(char *s);
void	hexa_conversion_min(unsigned int hexa);
void	hexa_conversion_big(unsigned int hexa);
void	hexa_conversion_p(unsigned long hexa);
int		nmbr_count(long hexa);	
int		unsigned_conversion(unsigned long pbe);
int     just_converting_int(char *s, int i, va_list ap);
int		just_converting_char(char *s, int i, va_list ap, char *str);
char    *ul_itoi(unsigned long number);
int     check_for_dot(char *s, int i);
int		check_for_convertion(char *s, int i);
int		dot_flag(char *s, int i, va_list ap, t_num nmbr);
int    putstr_ret(char *s);
int		after_befor_dot_flag(char *s, int i, va_list ap, t_num nmbr);
int     check_for_hyphien(char *s, int i);
int     hyphien_dot_flag(char *s, int i, va_list ap, t_num nmbr);
int		string_dot_flag(char *s, int i, va_list ap, t_num nmbr);
int     after_dot_flag(char *s, int i, va_list ap, t_num nmbr);
t_num		wich_conversion(char *s, int i, va_list ap, t_num nmbr);
int     s_after_dot_flag(char *s, int i, va_list ap);
int     left_flag_one(char *s, int i, va_list ap, t_num nmbr);
int		left_flag(char *s, int i, va_list ap, t_num nmbr);
int    left_flag_two(char *s, int i, va_list ap);
int     zero_flag(char *s, int i, va_list ap, t_num nmbr);
int     zero_flag_one(char *s, int i, va_list ap, t_num nmbr);
int		digit_flag(char *s, int i, va_list ap, t_num nmbr);
int     digit_flag_one(char *s, int i, va_list ap, t_num nmbr);
int     digit_flag_two(char *s, int i, va_list ap, t_num nmbr);
unsigned long     len(unsigned long number);
int     putchar_ret(char c);
int     zero_flag_mod(char *s, int i, va_list ap);
int     check_for_modulo(char *s, int i);
int     digit_flag_mod(char *s, int i, va_list ap);
int     left_flag_mod(char *s, int i, va_list ap);
int     dot_flag_mod(char *s, int i, va_list ap);
int     just_converting_int_f(char *s, int i, t_num d);
void    hyphien_execute(int k, int width_len, t_num nmbr, char *str);
t_num		first_to_use(int width_len, int k, t_num nmbr);
int     for_hyphien_flag(char *s, int *i, int *j, int *width_len);
int		for_hyphien_flag_two(int *k, char *s, int j, t_num *nmbr);
void    string_dot_helper(char *str, int width_len, int k);
int		string_before_dot(char *s, va_list ap, int *width_len, int *j);
int     helper_before_dot(char *s, int *j, va_list ap, int *width_len);
void    helper_after_dot(char *s, int k, int width_len, t_num nmbr);
void    to_use_zero(int k, int width, t_num *nmbr);
void    to_use_space_zero(int k, int width, t_num *nmbr);
void	wich_hexa(t_num *nmbr, va_list ap);
void	wich_hexa_p(t_num *nmbr, va_list ap);
void     s_precision(char *str, int width, int y);
int     s_left_flag_helper(int *width, char *s, int *i, int *j);
void    s_left_flag_helper_two(char *s, va_list ap, int j, int width);
int     while_left_flag(char *s, int *i, int z);
void    while_after_dot(int *width, char *s, int *after_width, int *j);
void    for_digit_flag(int width);
void    for_digit_flag_two(int width, t_num nmbr);
void    while_for_digit_flag(char *s, int *j, int *width);
void    null_digit_flag(char *str, int width);
void    star_digit_flag(int *width, char *s, va_list ap, int *j);
int    mod_helper(char *s, int *j, va_list ap, int *width_len);
void	hexa_p_helper(char *s, int i);
void	digit_helper(char *s, int j, int width, t_num nmbr);
void	hexa_p_helper(char *test, int i);
#endif
