/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:38:05 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/05 19:37:38 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}
