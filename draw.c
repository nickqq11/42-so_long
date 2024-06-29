/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:21 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/30 00:09:43 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sprite(t_game *game)
{
	int	i;

	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"graphic/player.xpm", &i, &i);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"graphic/gem.xpm", &i, &i);
}
