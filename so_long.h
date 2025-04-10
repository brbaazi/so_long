/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:17:06 by brbaazi           #+#    #+#             */
/*   Updated: 2025/04/05 19:39:18 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		p_count;
	int		e_count;
	int		c_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		moves;
	void	*img_background;
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	int		exit_found;
}			t_game;

int			init_game(t_game *game, char *map_file);
void		cleanup_game(t_game *game);

char		**read_map(char *filename);
t_map		*parse_map(char *filename);
int			is_rectangle(char **line);
int			accept_the_wall(char **map);
int			check_map_elements(t_map *map);
int			check_valid_path(t_map *map);

t_map		*free_map(t_map *map);
void		ft_free_tab(char **tab);
char		**ft_tabdup(char **tab);

void		render_map(t_game *game);
int			load_textures(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			close_game(t_game *game);
void		setup_hooks(t_game *game);

#endif