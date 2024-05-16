/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:09:52 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/16 14:52:24 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

typedef struct s_map
{
	int		items;
	char	**map;
}	t_map;

typedef struct s_sprite
{
	void	*player;
}	t_sprite;


typedef struct s_game
{
	int		w_length;
	int		w_lines;
	void	*mlx;
	void	*window;
	t_map	*map;
	t_sprite	sprite;
}	t_game;

int	main(int argc, char **argv);

void	check_map_extension(char **argv);

int	height_map(int fd);

void	fill_map(int fd, t_game *game);

void	create_map(t_game *game, char **argv);

void	print_map(t_game *game);

void	check_map_empty(t_game *game);

void	check_map_borders(t_game *game);

void	check_map_content(t_game *game);

void	fl_fill(char **map, int y, int x);

void	flood_fill(char **map);

void	print_map_error(char *error);

int	count_letters(char *str, char c);

void	*ft_empty_line(char **lines, int n);

char	**map_dup(t_game *game);

void	parsing_init(t_game *game);

void	init_game(t_game *game);

#endif
