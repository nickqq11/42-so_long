/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:16 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/11 21:34:23 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>

// // typedef struct	s_vars {
// // 	void	*mlx;
// // 	void	*win;
// // }				t_vars;

// // int	toclose(int keycode, t_vars *vars)
// // {
// // 	mlx_destroy_window(vars->mlx, vars->win);
// // 	return (0);
// // }

// // int	key_hook(int keycode, t_vars *vars)
// // {
// // 	printf("Hello from key_hook!\n");
// // 	return (0);
// // }

// // int mouse_hook(int mousecode, t_vars *vars)
// // {

// // 	if (mousecode == 1)
// // 		printf("left mouse hook\n");
// // 	else if (mousecode == 2)
// // 		printf("right mouse hook\n");
// // 	return(0);
// // }

// // int	main(void)
// // {
// // 	t_vars	vars;

// // 	vars.mlx = mlx_init();
// // 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// // 	mlx_key_hook(vars.win, key_hook, &vars);
// // 	mlx_mouse_hook(vars.win, mouse_hook, &vars);

// // 	mlx_loop(vars.mlx);
// // }
// // gcc so_long.c -o a -I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit  

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char imgpath;
	int imgwid;
	int imghei;
	int		x;
}				t_data;

int	render_next_frame(t_data *data)
{
	// Clear the window (fill it with black)
	mlx_clear_window(data->mlx, data->win);

	// Draw a rectangle that moves horizontally
	int rect_width = 50;
	int rect_height = 50;
	int color = 0x00FF0000; // Red

	// Draw the rectangle
	for (int y = 5; y < 5 + rect_height; y++)
	{
		for (int x = data->x; x < data->x + rect_width; x++)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
	}

	// Update the x position for the next frame
	data->x += 5;
	if (data->x > 640) // Reset to start position if it goes beyond window width
		data->x = 0;

	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 640, 480, "Moving Rectangle");
	data.x = 0;
	data.imgpath = "./map/test.xpm";
	data.img = mlx_xpm_file_to_image(data.mlx, data.imgpath, &data.imgwid, &data.imghei);

	//Register the render_next_frame function to be called continuously
	mlx_loop_hook(data.mlx, render_next_frame, &data);

	// Start the event loop
	mlx_loop(data.mlx);

	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./map/test.png";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	mlx_loop(mlx);
// }

