/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:08:01 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/27 09:41:27 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	parsing_init(t_game *game)
{
	char	**test;

	if ((game->w_length >= 300) && (game->w_lines >= 300))
		print_map_error("The map is too big", game);
	check_map_empty(game);
	check_map_borders(game);
	check_map_content(game);
	test = map_dup(game);
	flood_fill(test, game);
	free_dup_map(test);
}

void	free_dup_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}

char	**map_dup(t_game *game)
{
	int		y;
	char	**copy;

	y = 0;
	copy = malloc((game->w_lines) * sizeof(char *));
	while (y <= (game->w_lines))
	{
		if (game->map->map[y] == NULL)
		{
			copy[y] = NULL;
			break ;
		}
		copy[y] = ft_strdup(game->map->map[y]);
		if (!copy[y])
			return (ft_empty_line(copy, y));
		y++;
	}
	return (copy);
}
