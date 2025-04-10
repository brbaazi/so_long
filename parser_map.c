/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:16:19 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/05 22:04:12 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_append_tab(char **tab, char *line)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_tab[j] = ft_strdup(tab[j]);
		if (!new_tab[j])
		{
			ft_free_tab(new_tab);
			return (NULL);
		}
		j++;
	}
	new_tab[j] = ft_strdup(line);
	new_tab[j + 1] = NULL;
	ft_free_tab(tab);
	return (new_tab);
}

static int	ft_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	if (len >= 5 && filename[len - 5] == '/')
		return (0);
	return (1);
}

char	**read_map(char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	char	*tmp;

	if (!ft_ber_file(filename))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strtrim(line, "\n");
		free(line);
		map = ft_append_tab(map, tmp);
		free(tmp);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
