/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:04:56 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/16 14:52:01 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_xpm(t_sprite *sprite, t_game *game)
{
	int x;
	int y;
	
	sprite->player = mlx_xpm_file_to_image(game->mlx, "./sources/core/gato.xpm", &x, &y);
	printf("x: %d \n y: %d", x, y);
	if (sprite->player == NULL)
	{
		printf("\nFalleeeeee \n\n\n");
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, sprite->player, 1 * 64, 1 * 64);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920, 1080, "So_Long");
	printf("Aqui\n");
	init_xpm(&game->sprite, game);
	mlx_loop(game->mlx);
}
