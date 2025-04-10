/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:06:06 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/03 22:09:44 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->img_background = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/playerme.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &width, &height);
	return (game->img_background && game->img_player && game->img_wall
		&& game->img_collectible && game->img_exit);
}

static void	ft_image(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_background, x * 62,
		y * 62);
	if (game->map->grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 62, y
			* 62);
	if (game->map->grid[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 62, y
			* 62);
	}
	if (game->map->grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* 62, y * 62);
	if (game->map->grid[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 62,
			y * 62);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_image(game, x, y);
			x++;
		}
		y++;
	}
}
