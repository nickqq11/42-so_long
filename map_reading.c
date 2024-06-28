/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:57:54 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 16:49:38 by nhuang           ###   ########.fr       */
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
	if (!(game->width = ft_strlen(temp)))
		ft_printf("width counts error");
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

char **read_map(t_game *game, char **argv)
{
	int		i;
	char 	**map;

	game->fd = open(argv[1], O_RDONLY);
	if (!game->fd)
		ft_printf("fd not opening.\n");
	
}

int map_load(t_game *game, char **argv)
{
	count_height(game, argv);
}
