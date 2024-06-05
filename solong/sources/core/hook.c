/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:12:30 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/05 10:09:51 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


int key_pres_hook(int keycode, t_game *game)
{

	set_mv_player(keycode, game);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window);	
		exit(0);
	}
	printf(" \n %d, %d", game->player.y_pos,game->player.x_pos);
	printf("\n %d", game->player.steps);
	//mlx_clear_window(game->mlx, game->window);
	init_background(&game->sprite, game);
	//printf("\nnumero de pasos: %d numero de puntos: %d", game->player.steps, game->player.points);
	return (0);
}

int destroy_win_x(int keycode, t_game *game)
{
	(void)game;
	printf("%d\n", keycode);
	exit(0);
	return (0);
}

void	set_mv_player(int keycode, t_game *game)
{
	find_player_position(game);
	if(keycode == KEY_UP)
	{
		if (player_movement(game, game->player.x_pos, game->player.y_pos - 1))
			set_y_pos(game, -1);
	}
	else if (keycode == KEY_RIGHT)
	{
		if (player_movement(game, game->player.x_pos + 1, game->player.y_pos))
			set_x_pos(game, 1);
	}
	else if (keycode == KEY_LEFT)
	{
		if (player_movement(game, game->player.x_pos - 1, game->player.y_pos))
			set_x_pos(game, -1);
	}
	else if (keycode == KEY_DOWN)
	{
		if (player_movement(game, game->player.x_pos, game->player.y_pos + 1))
			set_y_pos(game, 1);
	}
}
