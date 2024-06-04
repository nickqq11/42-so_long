# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 15:50:16 by nhuang            #+#    #+#              #
#    Updated: 2024/06/04 17:18:25 by nhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

MINILIBX = minilibx
CC = gcc  -I/usr/include -Imlx_linux -I$(MINILIBX)
CFLAGS = -Wall -Wextra -Werror
LIB = -Lminilibx -lmlx


all: 
	@make -s -C $(MINILIBX)
	@$(CC) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:

fclean:
	@make fclean -C $(MINILIBX)
	@rm -rf $(NAME)

re: fclean all