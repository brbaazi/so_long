/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:49:16 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/03 21:11:10 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

void	cleanup_game(t_game *game)
{
	if (game)
	{
		destroy_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->map)
			free_map(game->map);
	}
}

int	init_game(t_game *game, char *map_file)
{
	game->map = parse_map(map_file);
	if (!game->map)
		return (0);
	game->exit_found = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->map->width * 62,
			game->map->height * 62, "So Long");
	if (!game->win || !load_textures(game))
	{
		cleanup_game(game);
		return (0);
	}
	render_map(game);
	return (1);
}
