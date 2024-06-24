/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:50:21 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/24 10:15:08 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//Check if the map is empty or is not valid
void	check_map_empty(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->w_lines - 2))
	{
		x = 0;
		while (x < game->w_length)
		{
			if (game->map->map[y][x] != '1' && game->map->map[y][x] != '0'
				&& game->map->map[y][x] != 'E' && game->map->map[y][x] != 'P'
				&& game->map->map[y][x] != 'C')
				print_map_error("EMPTY OR NOT VALID MAP \n", game);
			x++;
		}
		y++;
	}
}

//check map exist and is rectangular & check map borders
void	check_map_borders(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->w_lines - 1))
	{
		if (((int)strlen_no_tab(game->map->map[y])) != game->w_length)
			print_map_error("MAP NOT RECTANGULAR \n", game);
		x = 0;
		while (x < game->w_length)
		{
			if ((y == 0 || x == 0) && (game->map->map[y][x] != '1'))
				print_map_error("MAP NOT SURROUNDED BY WALLS \n", game);
			else if ((y == (game->w_lines - 2)|| x == (game->w_length - 1))
				&& game->map->map[y][x] != '1')
				print_map_error("MAP NOT SURROUNDED BY WALLS \n", game);
			x++;
		}
		y++;
	}
}

//count P E C
void	check_map_content(t_game *game)
{
	int	y;
	int	player;
	int	exit;

	y = 0;
	player = 0;
	exit = 0;
	game->map->items = 0;
	while (game->map->map && game->map->map[y])
	{
		player += count_ltrs(game->map->map[y], 'P');
		exit += count_ltrs(game->map->map[y], 'E');
		game->map->items += count_ltrs(game->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		print_map_error("THE NUMBER OF PLAYERS IS NOT CORRECT \n", game);
	if (exit != 1)
		print_map_error("THE NUMBER OF EXITS IS NOT CORRECT\n", game);
	if (game->map->items == 0)
		print_map_error("THE NUMBER OF ITEMS IS NOT DEFINED\n", game);
}

//check it has resolution (flood_fill)
void	fl_fill(char **map, int y, int x)
{
	map[y][x] = 'P';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C'
		|| map[y][x + 1] == 'E')
		fl_fill(map, y, x + 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C'
		|| map[y][x - 1] == 'E')
		fl_fill(map, y, x - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C'
		|| map[y + 1][x] == 'E')
		fl_fill(map, y + 1, x);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C'
		|| map[y - 1][x] == 'E')
		fl_fill(map, y - 1, x);
}

void	flood_fill(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	fl_fill(map, y, x);
	y = 0;
	while (map && map[y])
	{
		if ((count_ltrs(map[y], 'E') == 1) || (count_ltrs(map[y], 'C') == 1))
			print_dup_error(map, game);
		y++;
	}
}
