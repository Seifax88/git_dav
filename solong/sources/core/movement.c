/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:40:34 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/05 10:10:37 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	find_player_position(t_game *game)
{
	int		y;
	int		x;
	char	c;
	
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			c = game->map->map[y][x];
			if (c == 'P')
				{
					game->player.y_pos = y;
					game->player.x_pos = x;
				}
			x++;
		}
		y++;
	}
}

void	set_x_pos(t_game *game, int n)
{
	int	x;
	int y;

	x = game->player.x_pos + (n);
	y = game->player.y_pos;
	game->map->map[y][x] = 'P';
}

void	set_y_pos(t_game *game, int n)
{
		int	x;
	int y;

	x = game->player.x_pos;
	y = game->player.y_pos + (n);
	game->map->map[y][x] = 'P';
}

void	check_exit(t_game *game, char c)
{
	if (c == 'E' && game->player.points ==  game->map->items)
	{
		game->player.steps += 1;
		printf("Número de movimientos: %d\n", game->player.steps);
		exit(1);
		//deploy_message(1, game);
		//end_program(game, EXIT_SUCCESS);
	}
}

int	player_movement(t_game *game, int x, int y)
{
	char	c;

	c = game->map->map[y][x];
	//check_enemy(game, c);
	print_map(game);
	printf("\nnumero de pasos: %d numero de puntos: %d", game->player.steps, game->player.points);
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		game->player.steps += 1;
		game->player.points += 1;
		game->map->map[game->player.y_pos][game->player.x_pos] = '0';
		return (1);
	}
	if (c == '0' || c == 'p')
	{
		game->map->map[game->player.y_pos][game->player.x_pos] = '0';
		game->player.steps += 1;
		return (1);
	}
	check_exit(game, c);
	return (0);
}
