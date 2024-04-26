/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:11:40 by dgargant          #+#    #+#             */
/*   Updated: 2024/04/26 12:42:49 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map_extension(int fd, char **argv)
{
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error. Invalid map_path");
		exit("Error");
	}
}

//count width
int	length_map(int fd)
{
	char	buffer[1];
	int		nr_bytes;
	int		len;

	buffer[0] = '\0';
	nr_bytes = 1;
	len = 0;
	while (nr_bytes == 1)
	{
		nr_bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

//count height
int	height_map(int fd, int x)
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x || (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			line = NULL;
			exit("Error");
		}
		else
		{
			free(line);
			line = NULL;
			linecount++;
		}
	}
	return (linecount);
}

//map in s_game
void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	t_map	*map;

	i = 0;
	line = NULL;
	game->map = map; 
	while(1)
	{
		line = get_next_line(fd);
		if (i <= game->w_length)
			game->map->map[i] = line;
		else
			exit("Error");
		if (line == NULL)
			break ;
	}
}

//call functions
void	create_map(t_game *game, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		exit("Error");
	check_map_extension(fd, argv);
	game->w_length = (length_map(fd));
	game->w_lines = (height_map(fd, game->w_length));
	fill_map(fd, game);
	print_map(game->map->map, game->w_length);
}


void	print_map(t_map *map, int lines)
{
	for (int i = 0; i < lines; i++)
		printf("%s\n", map->map);
}