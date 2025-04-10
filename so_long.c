/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:08 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/06 12:07:00 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long maps/map.ber\n", 2);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game, argv[1]))
	{
		ft_putstr_fd("Error\n connection failed\n", 2);
		return (1);
	}
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
