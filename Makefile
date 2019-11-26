# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:43:55 by molabhai          #+#    #+#              #
#    Updated: 2019/11/25 21:28:04 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

FTSRC = ./libft

HEADER = ./libft/libft.h

LIBFTA = ./libft/libft.a

PRINTFHEADER = ft_printf.h 

PRINTFSRC = ft_printf.c conversion_type.c convert_to_hexa.c conversion_unsigned_type.c \
			only_flags.c utils_for_printf.c flag_helper.c dot_flag.c printf_utils_two.c \
			modulo.c converting_for_flags.c flag_helper_two.c dot_flag_helper_three.c \
			dot_flag_helper_four.c flag_helper_five.c flag_helper_six.c flag_helper_seven.c

PRINTFOBJ = $(PRINTFSRC:.c=.o)

all:
	+$(MAKE) -C $(FTSRC)
	$(CC) $(FLAGS) -c $(PRINTFSRC)
	ar rc  $(NAME) $(PRINTFOBJ)
	ranlib $(NAME)

clean :
	rm -rf *.o

re : clean all

.PHONY: clean all re
