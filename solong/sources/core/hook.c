/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:12:30 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/19 10:24:25 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_pres_hook(int keycode, t_game *game)
{
	set_mv_player(keycode, game);
	if (keycode == KEY_ESC)
	{
		destroy_all(game);
		exit(1);
	}
	init_background(&game->sprite, game);
	return (0);
}

int	destroy_win_x(t_game *game)
{
	destroy_all(game);
	exit(1);
	return (0);
}

void	set_mv_player(int keycode, t_game *game)
{
	find_player_position(game);
	if (keycode == KEY_UP || keycode == W_KEY)
	{
		if (player_movement(game, game->player.x_pos, game->player.y_pos - 1))
			set_y_pos(game, -1);
	}
	else if (keycode == KEY_RIGHT || keycode == D_KEY)
	{
		if (player_movement(game, game->player.x_pos + 1, game->player.y_pos))
			set_x_pos(game, 1);
	}
	else if (keycode == KEY_LEFT || keycode == A_KEY)
	{
		if (player_movement(game, game->player.x_pos - 1, game->player.y_pos))
			set_x_pos(game, -1);
	}
	else if (keycode == KEY_DOWN || keycode == S_KEY)
	{
		if (player_movement(game, game->player.x_pos, game->player.y_pos + 1))
			set_y_pos(game, 1);
	}
}
