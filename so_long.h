/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:12:22 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/27 14:51:22 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"


typedef	struct s_game
{
	int		fd;
	int		width;
	int		height;
	char	**map;
	char	**map_copy;
	int		exit_count;
	int		exit_x;
	int		exit_y;
	int		player_count;
	int		player_x;
	int		player_y;
	int		collectable_count;
	int		move_count;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*collectable;
	void	*exit;
	void	*wall;
	void	*floor;
}			t_game;


#endif