/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:04:56 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/18 12:42:15 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_imgs(t_sprite *sprite, t_game *game)
{
	int x;
	int y;
	
	sprite->cat = mlx_xpm_file_to_image(game->mlx, "./assets/Cat.xpm", &x, &y);
	sprite->cat2 = mlx_xpm_file_to_image(game->mlx, "./assets/Cat2.xpm", &x, &y);
	sprite->background = mlx_xpm_file_to_image(game->mlx, "./assets/Grass.xpm", &x, &y);
	sprite->bush = mlx_xpm_file_to_image(game->mlx, "./assets/Bush.xpm", &x, &y);
	sprite->house = mlx_xpm_file_to_image(game->mlx, "./assets/House.xpm", &x, &y);
	sprite->egg = mlx_xpm_file_to_image(game->mlx, "./assets/Egg1.xpm", &x, &y);
	sprite->chiken = mlx_xpm_file_to_image(game->mlx, "./assets/Chiken1.xpm", &x,&y);
	sprite->chiken2 = mlx_xpm_file_to_image(game->mlx, "./assets/Chiken2.xpm", &x,&y);
	error_create_img(&game->sprite, game);
}

void	error_create_img(t_sprite *sprite, t_game *game)
{
	if (sprite->egg == NULL || sprite->background == NULL
		|| sprite->bush == NULL || sprite->cat == NULL
		|| sprite->chiken == NULL || sprite->chiken2 == NULL
		|| sprite->house == NULL)
	{
		print_map_error("Error loading images", game);
		destroy_all(game);
	}
}


void	put_imgs(t_game *game, t_sprite *sprite, int y, int x)
{
	char	c;
	
	c = game->map->map[y][x];
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, sprite->background, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, sprite->bush, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, sprite->cat, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, sprite->house, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, sprite->egg, x * 64, y * 64);
	if (c == 'N')
		mlx_put_image_to_window(game->mlx, game->window, sprite->chiken, x * 64, y * 64);
}

void	init_background(t_sprite *sprite, t_game *game)
{
	int		y;
	int		x;
	
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			put_imgs(game, sprite, y, x);
			x++;
		}
		y++;
	}
	mlx_set_font(game->mlx, game->window, "12x24romankana");
	print_counter(game);
}

void	init_game(t_game *game)
{
	int	y;
	int x;
	
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &x, &y);
	if (x < (game->w_length * 64) || y < (game->w_lines * 64))
	{
		ft_printf("Resolution error, %d x %d", (game->w_length * 64), (game->w_lines * 64));
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game);
		exit(0);
	}
	game->window = mlx_new_window(game->mlx, (game->w_length * 64), ((game->w_lines - 1) * 64), "So_Long");
	init_imgs(&game->sprite, game);
	find_exit_position(game);
	game->player.steps = 0;
	game->player.points = 0;
	init_background(&game->sprite, game);
	mlx_hook(game->window, 17, 0, destroy_win_x, game);
	mlx_hook(game->window, 2, 1L >> 0, key_pres_hook, game);
	mlx_loop_hook(game->mlx, chiken_animations, game);
	//mlx_loop_hook(game->mlx, player_animations, game);
	mlx_loop(game->mlx);
}
