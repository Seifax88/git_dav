/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:09:52 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/20 14:19:49 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

# ifndef keys
#  define KEY_ESC	65307
#  define KEY_DOWN	65364
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_UP	65362
#  define W_KEY		119
#  define A_KEY		97
#  define S_KEY		115
#  define D_KEY		100
# endif

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

typedef struct s_player
{
	int	points;
	int	steps;
	int	y_pos;
	int	x_pos;
}	t_player;

typedef struct s_map
{
	int		y_exit;
	int		x_exit;
	int		items;
	char	**map;
}	t_map;

typedef struct s_sprite
{
	void	*cat;
	void	*background;
	void	*bush;
	void	*house;
	void	*egg;
}	t_sprite;

typedef struct s_game
{
	int			w_length;
	int			w_lines;
	void		*mlx;
	void		*window;
	t_map		*map;
	t_sprite	sprite;
	t_player	player;
}	t_game;

int		main(int argc, char **argv);

void	check_map_extension(char **argv, t_game *game);

int		height_map(int fd);

void	fill_map(int fd, t_game *game);

void	create_map(t_game *game, char **argv);

void	print_map(t_game *game);

void	count_items(t_game *game);

void	check_map_empty(t_game *game);

void	check_map_borders(t_game *game);

void	check_map_content(t_game *game);

void	free_dup_map(char **map);

void	fl_fill(char **map, int y, int x);

void	flood_fill(char **map, t_game *game);

void	print_map_error(char *error, t_game *game);

void	print_dup_error(char **map, t_game *game);

int		count_ltrs(char *str, char c);

void	*ft_empty_line(char **lines, int n);

char	**map_dup(t_game *game);

void	parsing_init(t_game *game);

void	init_game(t_game *game);

void	init_imgs(t_sprite *sprite, t_game *game);

void	error_create_img(t_sprite *sprite, t_game *game);

void	init_background(t_sprite *sprite, t_game *game);

void	put_imgs(t_game *game, t_sprite *sprite, int y, int x);

int		key_pres_hook(int keycode, t_game *game);

int		destroy_win_x(t_game *game);

void	find_exit_position(t_game *game);

void	find_player_position(t_game *game);

int		player_movement(t_game *game, int x, int y);

void	set_mv_player(int keycode, t_game *game);

void	set_y_pos(t_game *game, int n);

void	set_x_pos(t_game *game, int n);

void	check_exit(t_game *game, char c);

int		check_egg(t_game *game, char c);

void	free_map(t_game *game);

void	destroy_all(t_game *game);

void	win_message(void);

#endif
