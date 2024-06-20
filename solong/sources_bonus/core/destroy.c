/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:38:09 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/20 11:07:03 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (game->sprite.cat2)
		mlx_destroy_image(game->mlx, game->sprite.cat2);
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

void	resolution_error(t_game *game)
{
	ft_printf("Resolution error, %d x %d", (game->w_length * 64),
		(game->w_lines * 64));
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
}
