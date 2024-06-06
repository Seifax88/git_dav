/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:40:34 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/06 12:18:06 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_exit(t_game *game, char c)
{
	if (c == 'E' && game->player.points ==  game->map->items)
	{
		game->player.steps += 1;
		printf("\nSteps: %d\n", game->player.steps);
		destroy_all(game);
		exit(1);
		//deploy_message(1, game);
	}
}

void	check_enemy(t_game *game,char c)
{
	if (c == 'N')
	{
		game->player.steps += 1;
		destroy_all(game);
		exit(1);
	}
}

int	player_movement(t_game *game, int x, int y)
{
	char	c;

	c = game->map->map[y][x];
	check_enemy(game, c);
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		game->player.steps += 1;
		game->player.points += 1;
		if (game->player.points == game->map->items)
			game->map->map[game->map->y_exit][game->map->x_exit] = 'E';
		printf("\nSteps: %d points: %d", game->player.steps, game->player.points);
		game->map->map[game->player.y_pos][game->player.x_pos] = '0';
		return (1);
	}
	if (c == '0' || c == 'P')
	{
		game->map->map[game->player.y_pos][game->player.x_pos] = '0';
		game->player.steps += 1;
		printf("\nSteps: %d points: %d", game->player.steps, game->player.points);
		return (1);
	}
	check_exit(game, c);
	return (0);
}
