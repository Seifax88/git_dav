/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:36:13 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/20 10:29:55 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	chiken_animations(t_game *game)
{
	static int	counter;

	if (!&game->sprite.chiken2)
		return (1);
	if (!counter)
		counter = 0;
	put_chiken_animation(game, counter);
	player_animations(game);
	counter++;
	if (counter == 700000)
		counter = 0;
	return (0);
}

void	player_animations(t_game *game)
{
	static int	counter;

	if (!counter)
		counter = 0;
	put_player_animation(game, counter);
	counter++;
	if (counter == 150000)
		counter = 0;
}

void	put_chiken_animation(t_game *game, int counter)
{
	int		y;
	int		x;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			if (game->map->map[y][x] == 'N')
			{
				chiken_iter(game, counter, x, y);
			}
			x++;
		}
		y++;
	}
}

void	put_player_animation(t_game *game, int counter)
{
	int		y;
	int		x;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			player_iter(game, counter, x, y);
			x++;
		}
		y++;
	}
}
