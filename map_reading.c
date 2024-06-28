/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:57:54 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 12:18:19 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_height(t_game *game, char **argv)
{
	char *temp;

	game->fd = open(argv[1], O_RDONLY);
	if (!game->fd)
		ft_printf("fd not opening.\n");
	temp = get_next_line(game->fd);
	while(temp)
	{
		game->height++;
		free(temp);
		temp = get_next_line(game->fd);
	}
	if (game->height == 0)
		ft_printf("empty map file");
	close(game->fd);
}

int count_width(t_game *game, )

int map_load(t_game *game, char **argv)
{
	count_height(game, argv);
}
