/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:43:30 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/20 10:30:33 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chiken_iter(t_game *game, int counter, int x, int y)
{
	t_sprite	p_sprite;

	p_sprite = game->sprite;
	if (counter == 200000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.chiken2, x * 64, y * 64);
	if (counter == 215000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.chiken, x * 64, y * 64);
	if (counter == 600000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.chiken2, x * 64, y * 64);
	if (counter == 635000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.chiken, x * 64, y * 64);
}

void	player_iter(t_game *game, int counter, int x, int y)
{
	t_sprite	p_sprite;

	p_sprite = game->sprite;
	if (game->map->map[y][x] == 'P' && counter == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat2, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' && counter == 25000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' && counter == 50000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat2, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' && counter == 75000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' && counter == 100000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat2, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' && counter == 125000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.cat, x * 64, y * 64);
}
