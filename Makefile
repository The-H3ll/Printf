# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 03:23:08 by molabhai          #+#    #+#              #
#    Updated: 2019/12/19 07:15:35 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_conversion.c print_convert_two.c ft_printf_utils.c \
	   flag_utils.c flags.c flag_helper.c flag_helper_two.c flag_helper_three.c \
	   flag_helper_four.c ft_strlen.c ft_strdup.c ft_isdigit.c ft_memset.c ft_strlen.c \
	   ft_atoi.c ft_bzero.c ft_calloc.c


OBJ = $(SRCS:.c=.o)

all:
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

re : clean all

fclean : clean
	rm -rf $(NAME)

.PHONY: clean re all
