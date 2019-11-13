# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:43:55 by molabhai          #+#    #+#              #
#    Updated: 2019/11/09 21:51:36 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

FTSRC = ./libft

HEADER = ./libft/libft.h

PRINTFHEADER = ft_printf.h 

PRINTFSRC = ft_printf.c conversion_type.c convert_to_hexa.c conversion_unsigned_type.c \
			only_flags.c

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