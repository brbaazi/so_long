/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:26 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/05 19:37:59 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	try_move_condition(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	if (game->map->grid[new_y][new_x] == 'E')
	{
		if (game->map->c_count == 0)
		{
			ft_putstr_fd("Congratulations! You won!\n", 1);
			close_game(game);
			return (1);
		}
		return (2);
	}
	return (2);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->map->p_x;
	old_y = game->map->p_y;
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->c_count--;
	}
	if (old_x == game->map->e_x && old_y == game->map->e_y)
	{
		game->map->grid[old_y][old_x] = 'E';
	}
	else
	{
		game->map->grid[old_y][old_x] = '0';
	}
	game->map->grid[new_y][new_x] = 'P';
	game->map->p_x = new_x;
	game->map->p_y = new_y;
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
	render_map(game);
}

static int	try_move(t_game *game, int new_x, int new_y)
{
	int	condition;

	condition = try_move_condition(game, new_x, new_y);
	if (condition == 0)
		return (0);
	update_player_position(game, new_x, new_y);
	return (1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		try_move(game, game->map->p_x, game->map->p_y - 1);
	else if (keycode == 115 || keycode == 65364)
		try_move(game, game->map->p_x, game->map->p_y + 1);
	else if (keycode == 97 || keycode == 65361)
		try_move(game, game->map->p_x - 1, game->map->p_y);
	else if (keycode == 100 || keycode == 65363)
		try_move(game, game->map->p_x + 1, game->map->p_y);
	return (0);
}
