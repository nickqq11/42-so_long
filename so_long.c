/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:16 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/27 15:03:04 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>

// // gcc so_long.c -o a -I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit  

void game_start(t_game *game)
{
	game->mlx_ptr = mlx_init();
	//if (!game->mlx_ptr)
		//ft_printf("mlx not initiate");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height, "so_long");
	//if (!game->win_ptr)
		//ft_printf("win not initiate");
}

int main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
		return (0);
	game_start(&game);
}