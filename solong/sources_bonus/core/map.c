/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:11:40 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/24 14:22:11 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_extension(char **argv, t_game *game)
{
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4)
		|| argv[1][ft_strlen(argv[1]) - 5] == '/'
		|| ft_strncmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf(RED "\n Error. Invalid map_path \n" RESET);
		free(game->map);
		game->map = NULL;
		exit(1);
	}
}

//count height
int	height_map(int fd)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		line = NULL;
		linecount++;
	}
	return (linecount);
}

//map in s_game
void	fill_map(int fd, t_game *game)
{
	int		i;

	i = 0;
	game->map->map = malloc((game->w_lines) * sizeof(char *));
	while (1)
	{
		game->map->map[i] = get_next_line(fd);
		if (game->map->map[i] == NULL)
		{
			break ;
		}
		i++;
	}
}

void	count_items(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	game->map->items = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (x < game->w_length)
		{
			c = game->map->map[y][x];
			if (c == 'C')
			{
				game->map->items += 1 ;
			}
			x++;
		}
		y++;
	}
}

//call functions
void	create_map(t_game *game, char **argv)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	game->map = map;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED "\n Error, please use a valid map \n" RESET);
		free(map);
		map = NULL;
		exit(1);
	}
	check_map_extension(argv, game);
	game->w_lines = (height_map(fd));
	close(fd);
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	fill_map(fd, game);
	game->w_length = (int)strlen_no_tab(game->map->map[0]);
	count_items(game);
}
