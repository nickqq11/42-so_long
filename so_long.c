/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:16 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 11:13:12 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include "printf/ft_printf.h"

// // gcc so_long.c -o a -I./minilibx -L./minilibx -lmlx -I./ft_printf -L./printf -lftprintf -I./libft -L./libft  -framework OpenGL -framework AppKit  

// void game_end (t_game *game)
// {
	
// }

void exit_game(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	ft_printf("Game exited, memory freed.\n");
	exit(EXIT_SUCCESS);
}

void game_start(t_game *game)
{
	game->width = 300;
	game->height = 300;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_printf("mlx_ptr not initiate\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height, "so_long");
	if (!game->win_ptr)
		ft_printf("mlx_new_window not initiate\n");
}

int main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
		return (ft_printf("please load .ber map file\n"));
	check_all(argv);
	game_start(&game);
	map_load(&game, argv);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_game, &game);
	mlx_loop(game.mlx_ptr);
}