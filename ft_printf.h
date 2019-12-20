/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:42:37 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/18 05:36:39 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flag
{
	int					zero;
	int					minus;
	int					dot;
	int					nmbr_len;
	int					len_before_flag;
	int					len_after_flag;
	int					wich_conversion;
	long				int_conversion;
	unsigned int		hexa_conversion;
	unsigned int		unsigned_conversion;
	char				char_conversion;
	unsigned long long	adress_conversion;
	char				*str_conversion;
}					t_flag;

int					ft_printf(const char *s, ...);
void				put_nmbr(long i);
void				ft_putchar(char c);
int					nmbr_len(long i);
int					convert_hexa(unsigned int i, int z, int y);
int					print_char(int c);
int					print_string(char *s);
int					print_hexa(unsigned int i, int z);
int					print_int(int i);
int					print_unsigned_int(unsigned int i);
int					print_hex_adress(unsigned long long i, int z);
void				revers_print(char *str, int k);
int					hexa_convert(int l, int z);
int					print_mod();
void				take_conversion(char *s, int i, t_flag *check, va_list ap);
void				put_flag(char *s, int *i, t_flag *check, va_list ap);
int					conversion_for_print(char *s, int i);
int					print_conversion(t_flag *check);
int					check_for_dot(char *s, int i);
void				dot_flag(t_flag *check, int *m, int *l);
void				minus_flag(t_flag *check, int m, int l);
void				no_zero_no_minus(t_flag *check, int m, int l);
void				flag_zero(t_flag *check, int l);
int					big_hexa(int l);
void				str_or_null(t_flag *check, int *i, int *l, char **s);
void				before_equal_after(t_flag *check);
void				before_less_after(t_flag *check);
void				check_minus_dot(int *m, int *l, t_flag *check);
void				put_for_dot(void);
void				take_char(t_flag *check, va_list ap);
void				take_string(t_flag *check, va_list ap);
void				take_hexa(t_flag *check, va_list ap);
void				take_unsigned(t_flag *check, va_list ap);
void				take_adress(t_flag *check, va_list ap);
void				put_flag_one(t_flag *check);
void				put_flag_two(t_flag *check);
void				put_flag_three(t_flag *check);
void				put_it(t_flag *check, int *i, char *s, va_list ap);
void				flag_checker(char *s, int *i, t_flag *check);
void				take_len(char *s, int *i, t_flag *check, va_list ap);
void				take_conversio(char *s, int i, t_flag *check, va_list ap);
int					check_condition_one(t_flag *check);
int					check_condition_two(t_flag *check);
int					check_condition_three(t_flag *check);
int					check_condition_four(t_flag *check);
void				*ft_memset(void *s, int c, size_t len);
int					ft_isdigit(int c);
char				*ft_strdup(char *s);
size_t				ft_strlen(char const *s);
int					ft_atoi(char const *s);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t c, size_t size);
#endif
