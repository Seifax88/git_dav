/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:04:56 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/29 10:12:22 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_xpm(t_sprite *sprite, t_game *game)
{
	int x;
	int y;
	
	sprite->player = mlx_xpm_file_to_image(game->mlx, "./assets/Cat1.xpm", &x, &y);
	printf("x: %d \n y: %d", x, y);
	if (sprite->player == NULL)
	{
		printf("\nFalleeeeee \n\n\n");
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, sprite->player, 1 * 64, 1 * 64);
}

void	init_background(t_sprite *sprite, t_game *game)
{
	int		y;
	int		x;
	char	c;

	sprite->background = mlx_xpm_file_to_image(game->mlx, "./assets/Grass.xpm", &x, &y);
	sprite->bush = mlx_xpm_file_to_image(game->mlx, "./assets/Bush.xpm", &x, &y);
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		printf("%d = ", y);
		while (x < game->w_length)
		{
			c = game->map->map[y][x];
			if (c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'N' || c == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window, sprite->background, x * 64, y * 64);
				printf("Gato");
			}
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->window, sprite->bush, x * 64, y * 64);
			printf("\t%d\n", x);
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (game->w_length * 64), ((game->w_lines - 1) * 64), "So_Long");
	printf("Aqui\n");
	init_background(&game->sprite, game);
	//init_xpm(&game->sprite, game);
	//test(game);
	mlx_loop(game->mlx);
}
