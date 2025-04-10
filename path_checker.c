/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:59 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/04 12:24:31 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct s_flood_info
{
	char	**map;
	int		collectibles;
	int		found_exit;
}			t_flood;

static void	flood_fill(t_flood *data, int x, int y)
{
	if (data->map[y][x] == '1' || data->map[y][x] == 'F')
		return ;
	if (data->map[y][x] == 'E')
		data->found_exit = 1;
	if (data->map[y][x] == 'C')
		data->collectibles--;
	data->map[y][x] = 'F';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

int	check_valid_path(t_map *map)
{
	char	**tmp_map;
	t_flood	flood_data;

	tmp_map = ft_tabdup(map->grid);
	if (!tmp_map)
		return (0);
	flood_data.map = tmp_map;
	flood_data.collectibles = map->c_count;
	flood_data.found_exit = 0;
	flood_fill(&flood_data, map->p_x, map->p_y);
	ft_free_tab(tmp_map);
	return (flood_data.collectibles == 0 && flood_data.found_exit == 1);
}
