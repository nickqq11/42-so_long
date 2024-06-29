/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:40 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/30 00:02:17 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char **argv)
{
	char	*temp;

	temp = ft_strrchr(argv[1], '.');
	if (!temp)
		return (ft_printf("map file format not .ber"));
	return (ft_strncmp(temp, ".ber", 4));
}

void	check_sprite(t_game *game, char *str, int y)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'P')
		{
			game->player_count++;
			game->player_x = i;
			game->player_y = y;
		}
		else if (str[i] == 'E')
		{
			game->exit_count++;
			game->exit_x = i;
			game->exit_y = y;
		}
		else if (str[i] == 'C')
			game->collectable_count++;
	}
	if (game->player_count > 1 || game->exit_count > 1)
		ft_terminate(game, "player or exit != 1");
	if (game->collectable_count < 1)
		ft_terminate(game, "no collectable");
}

void	check_wall(t_game *game)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < game->width)
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			ft_terminate(game, "no up down wall.\n");
	i = -1;
	temp = ft_strlen(game->map[0]);
	while (++i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width -1] != '1')
			ft_terminate(game, "no side wall.\n");
		if (temp != ft_strlen(game->map[i]))
			ft_terminate(game, "map not rectangle.\n");
	}
}

void	check_route(t_game *game, char **map_copy, int x, int y)
{
	int	exit_found;
	int	collec_found;

	if (map_copy[y][x] == '1')
		return (0);
	else if (map_copy[y][x] == 'E')
		exit_found = 1;
	else if (map_copy[y][x] == 'C')
		collec_found++;
	map_copy[y][x] = 1;
	check_route(game, map_copy, x + 1, y);
	check_route(game, map_copy, x - 1, y);
	check_route(game, map_copy, x, y + 1);
	check_route(game, map_copy, x, y - 1);
	return (collec_found == game->collectable_count && exit_found);
}

int	check_all(t_game *game, char **argv)
{
	check_ber(argv);
	check_wall(game);
	check_route(game, game->map_copy, game->player_x, game->player_y);
}
