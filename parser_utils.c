/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:07:27 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/06 12:34:42 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_tabdup(char **tab)
{
	char	**new_tab;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

t_map	*free_map(t_map *map)
{
	if (map)
	{
		if (map->grid)
			ft_free_tab(map->grid);
		free(map);
	}
	return (NULL);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = read_map(filename);
	if (!map->grid)
		return (ft_printf("read_map() failed\n"), free_map(map));
	map->height = ft_tablen(map->grid);
	map->width = ft_strlen(map->grid[0]);
	if (!is_rectangle(map->grid))
		ft_printf("error/nMap is NOT rectangle\n");
	else if (!accept_the_wall(map->grid))
		ft_printf("Map is NOT surrounded by walls\n");
	else if (!check_map_elements(map))
		ft_printf("Invalid map elements (P, E, C)\n");
	else if (!check_valid_path(map))
		ft_printf("No valid path!\n");
	if (!is_rectangle(map->grid) || !accept_the_wall(map->grid)
		|| !check_map_elements(map) || !check_valid_path(map))
		return (free_map(map));
	return (map);
}
