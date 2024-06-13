/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:47:49 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/13 10:24:55 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map_error(char *error, t_game *game)
{
	ft_printf("\n ERROR, %s", error);
	free_map(game);
	exit(1);
}



int	count_letters(char *str, char c)
{
	int	num_letters;
	int	i;

	num_letters = 0;
	i = 0;
	if (!str)
		return(-1);
	while(str && str[i])
	{
		if (str[i] == c)
			num_letters++;
		i++;
	}
	return (num_letters);
}


void	*ft_empty_line(char **lines, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
	return (NULL);
}

void	print_dup_error(char **map, t_game *game)
{
	ft_printf("\n ERROR, WRONG MAP");
	free_map(game);
	free_dup_map(map);
	exit(1);
}

void	free_map(t_game *game)
{
	int y;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		free(game->map->map[y]);
		y++;
	}
	free(game->map->map);
	game->map->map = NULL;
	free(game->map);
	game->map = NULL;
}