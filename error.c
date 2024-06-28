/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:59:19 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 21:58:20 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_destroy_sprite(t_game *game)
{

}

void ft_terminate(t_game *game, char *msg)
{
	if (game->fd)
		close(game->fd);
	
}