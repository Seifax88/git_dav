/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:09:52 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/09 09:29:49 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int		items;
	char	**map;
}	t_map;

typedef struct s_game
{
	int		w_length;
	int		w_lines;
	t_map	*map;
}	t_game;

void	check_map_extension(char **argv);

int	length_map(int fd);

int	height_map(int fd);

void	fill_map(int fd, t_game *game);

void	create_map(t_game *game, char **argv);

void	print_map(t_game *game);

int	main(int argc, char **argv);

void	print_map_error(char *error);

void	check_map_empty(t_game *game);

void	check_map_borders(t_game *game);

int	count_letters(char *str, char c);

void	check_map_content(t_game *game);

#endif
