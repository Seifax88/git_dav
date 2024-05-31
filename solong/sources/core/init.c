/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:04:56 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/31 10:32:53 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_imgs(t_sprite *sprite, t_game *game)
{
	int x;
	int y;
	
	sprite->player = mlx_xpm_file_to_image(game->mlx, "./assets/Cat1.xpm", &x, &y);
	sprite->background = mlx_xpm_file_to_image(game->mlx, "./assets/Grass.xpm", &x, &y);
	sprite->bush = mlx_xpm_file_to_image(game->mlx, "./assets/Bush.xpm", &x, &y);
	sprite->house = mlx_xpm_file_to_image(game->mlx, "./assets/House.xpm", &x, &y);
	sprite->egg = mlx_xpm_file_to_image(game->mlx, "./assets/Egg1.xpm", &x, &y);
}

void	init_background(t_sprite *sprite, t_game *game)
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
			if (c == '0')
				mlx_put_image_to_window(game->mlx, game->window, sprite->background, x * 64, y * 64);
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->window, sprite->bush, x * 64, y * 64);
			if (c == 'P')
				mlx_put_image_to_window(game->mlx, game->window, sprite->player, x * 64, y * 64);
			if (c == 'E')
				mlx_put_image_to_window(game->mlx, game->window, sprite->house, x * 64, y * 64);
			if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->window, sprite->egg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int destroy_win(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		printf("hola");
		mlx_destroy_window(game->mlx, game->window);	
	}
	return (0);
}

int test_hook(int keycode, t_game *game)
{
	(void)game;
	//printf("Código = ");
	printf("%d\n", keycode);
	exit(0);
	return (0);
}

void	init_game(t_game *game)
{
	int	y;
	int x;
	
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &x, &y);
	printf("\n%d x %d\n", x, y);
	if (x < (game->w_length * 64) || y < (game->w_lines * 64))
	{
		printf("Resolution error, %d x %d", (game->w_length * 64), (game->w_lines * 64));
		exit(0);
	}
	game->window = mlx_new_window(game->mlx, (game->w_length * 64), ((game->w_lines - 1) * 64), "So_Long");
	printf("Aqui\n");
	init_imgs(&game->sprite, game);
	init_background(&game->sprite, game);
	mlx_hook(game->window, 2, 1L >> 0, destroy_win, game);
	mlx_hook(game->window, 17, 1L >> 0, test_hook, game);
	mlx_loop(game->mlx);
	//mlx_destroy_display(game->mlx);
    //free(game->mlx);
}
