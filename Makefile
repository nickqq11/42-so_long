# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 15:50:16 by nhuang            #+#    #+#              #
#    Updated: 2024/06/04 17:40:35 by nhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

MINILIBX = minilibx
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit


all: 
	@make -C $(MINILIBX)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME)

clean:

fclean:
	@make fclean -C $(MINILIBX)
	@rm -rf $(NAME)

re: fclean all