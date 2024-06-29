/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:59:19 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/29 20:36:56 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_sprite(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
}

void	ft_terminate(t_game *game, char *msg)
{
	if (game->fd)
		close(game->fd);
	ft_destroy_sprite(game);
}
