/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:36:13 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/18 14:06:03 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	chiken_animations(t_game *game)
{
	static int	counter;
	
	if (!&game->sprite.chiken2)
		return(1);
	if (!counter)
		counter = 0;
	put_chiken_animation(&game->sprite, game, counter);
	player_animations(game);
	counter++;
	
	if (counter == 700000)
		counter = 0;
	return (0);
}

void	player_animations(t_game *game)
{
	static int	counter;
	
	/*if (!&game->sprite.chiken2)
		return(1);*/
	if (!counter)
		counter = 0;
	put_player_animation(&game->sprite, game, counter);
	
	counter++;
	
	if (counter == 150000)
		counter = 0;
	//return (0);
}

void	put_chiken_animation(t_sprite *sprite, t_game *game, int counter)
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
				if (counter == 200000)
					mlx_put_image_to_window(game->mlx, game->window, sprite->chiken2, x * 64, y * 64);
				if (counter == 215000)
					mlx_put_image_to_window(game->mlx, game->window, sprite->chiken, x * 64, y * 64);
				if (counter == 600000)
					mlx_put_image_to_window(game->mlx, game->window, sprite->chiken2, x * 64, y * 64);
				if (counter == 635000)
					mlx_put_image_to_window(game->mlx, game->window, sprite->chiken, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_player_animation(t_sprite *sprite, t_game *game, int counter)
{
	int		y;
	int		x;
	
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			if (game->map->map[y][x] == 'P' && counter == 0)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat2, x * 64, y * 64);
			if (game->map->map[y][x] == 'P' && counter == 25000)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat, x * 64, y * 64);
			if (game->map->map[y][x] == 'P' && counter == 50000)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat2, x * 64, y * 64);
			if (game->map->map[y][x] == 'P' && counter == 75000)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat, x * 64, y * 64);
			if (game->map->map[y][x] == 'P' && counter == 100000)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat2, x * 64, y * 64);
			if (game->map->map[y][x] == 'P' && counter == 125000)
				mlx_put_image_to_window(game->mlx, game->window, sprite->cat, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
