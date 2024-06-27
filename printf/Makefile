# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:32:19 by nhuang            #+#    #+#              #
#    Updated: 2023/06/27 18:21:04 by nhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

SOURCE = ft_printf.c \
	ft_pointer.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_putnbr_un.c \
	ft_putnbr.c \
	ft_putstr.c 

OBJECTS = $(SOURCE:%.c=%.o)

.PHONY : clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo "compiling $@ from $^"
	@ar src $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) -c $< -o $@

clean :
	@rm -f *.o 

fclean : clean
	@rm -f $(NAME)

re :
	@make fclean && make clean && make all