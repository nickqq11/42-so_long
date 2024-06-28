/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:57:54 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 20:46:29 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_height(t_game *game, char **argv)
{
	char *temp;

	game->fd = open(argv[1], O_RDONLY);
	if (!game->fd)
		return(ft_printf("fd not opening.\n"), NULL);
	temp = get_next_line(game->fd);
	if (!(game->width = ft_strlen(temp)))
		return(ft_printf("width counts error\n"), NULL);
	while(temp)
	{
		game->height++;
		free(temp);
		temp = get_next_line(game->fd);
	}
	if (game->height == 0)
		return(ft_printf("empty map file\n"), NULL);
	close(game->fd);

}

char **read_map(t_game *game, char **argv)
{
	int		i;
	char 	**map;

	game->fd = open(argv[1], O_RDONLY);
	if (!game->fd)
		return(ft_printf("fd not opening.\n"), NULL);
	map = malloc((game->height + 1) * sizeof(char *) );
	if (!map)
		return(ft_printf("malloc error.\n"), NULL);
	i = -1;
	while(++i < game->height)
	{
		map[i] = get_next_line(game->fd);
		if (map[i][game->width - 1] == '\n')
			map[i][game->width - 1] = '0';
	}
	map[i] = NULL;
	close(game->fd);
	return(map);
}

int map_load(t_game *game, char **argv)
{
	count_height(game, argv);
	game->map = read_map(game, argv);
	if (!game->map)
		return(ft_printf("read_map function error"), NULL);
	game->map_copy = read_map(game, argv);
}
