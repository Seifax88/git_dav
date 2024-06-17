/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:06:25 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/17 10:26:02 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	find_exit_position(t_game *game)
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
			if (c == 'E')
				{
					game->map->y_exit = y;
					game->map->x_exit = x;
					game->map->map[y][x] = '0';
				}
			x++;
		}
		y++;
	}
}

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

void	print_counter(t_game *game)
{
	int	y;
	int	x;
	int	steps;
	char	*str;

	y = game->w_lines - 1;
	x = 1;
	steps = game->player.steps;
	str = ft_itoa(steps);
	mlx_string_put(game->mlx, game->window, x * 64, y * 64, 0xB500EA ,"Steps: ");
	mlx_string_put(game->mlx, game->window, (x + 2) * 64, y * 64, 0xB500EA , str);
	free(str);
}

void	destroy_all(t_game *game)
{
	if (game->sprite.house)
		mlx_destroy_image(game->mlx, game->sprite.house);
	if (game->sprite.bush)
		mlx_destroy_image(game->mlx, game->sprite.bush);
	if (game->sprite.egg)
		mlx_destroy_image(game->mlx, game->sprite.egg);
	if (game->sprite.background)
		mlx_destroy_image(game->mlx, game->sprite.background);
	if (game->sprite.cat)
		mlx_destroy_image(game->mlx, game->sprite.cat);
	if (game->sprite.chiken)
		mlx_destroy_image(game->mlx, game->sprite.chiken);
	if (game->sprite.chiken2)
		mlx_destroy_image(game->mlx, game->sprite.chiken2);
	mlx_destroy_window(game->mlx, game->window);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	free_map(game);
}

