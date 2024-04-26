/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:09:52 by dgargant          #+#    #+#             */
/*   Updated: 2024/04/26 12:41:28 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_game
{
	int		w_length;
	int		w_lines;
	t_map	*map;
}	t_game;

void	check_map_extension(int fd, char **argv);

int	length_map(int fd);

int	height_map(int fd, int x);

void	fill_map(int fd, t_game *game);

void	create_map(t_game *game, char **argv);

void	print_map(t_map *map, int lines);

#endif
