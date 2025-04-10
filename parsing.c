/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:56:28 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/05 19:09:08 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangle(char **line)
{
	size_t	len;
	int		i;

	if (!line || !line[0])
		return (0);
	len = ft_strlen(line[0]);
	i = 1;
	while (line[i])
	{
		if (ft_strlen(line[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	accept_the_wall(char **map)
{
	int	i;
	int	line;
	int	j;
	int	colons;

	(1) && (line = 0, j = 0, i = 0);
	while (map[line])
		line++;
	line--;
	colons = ft_strlen(map[0]) - 1;
	while (j <= colons)
	{
		if (map[0][j] != '1' || map[line][j] != '1')
			return (0);
		j++;
	}
	while (i <= line)
	{
		if (map[i][0] != '1' || map[i][colons] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	process_map_cell(t_map *map, int i, int j)
{
	if (map->grid[i][j] != '0' && map->grid[i][j] != '1'
		&& map->grid[i][j] != 'C' && map->grid[i][j] != 'E'
		&& map->grid[i][j] != 'P')
		return (0);
	if (map->grid[i][j] == 'P')
	{
		map->p_count++;
		map->p_x = j;
		map->p_y = i;
	}
	else if (map->grid[i][j] == 'E')
	{
		map->e_count++;
		map->e_x = j;
		map->e_y = i;
	}
	else if (map->grid[i][j] == 'C')
		map->c_count++;
	return (1);
}

int	check_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!process_map_cell(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (map->p_count == 1 && map->e_count == 1 && map->c_count >= 1)
		return (1);
	return (0);
}
