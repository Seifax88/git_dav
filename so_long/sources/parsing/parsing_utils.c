/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:47:49 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/09 09:30:03 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_map_error(char *error)
{
	printf("%s", error);
	exit(1);
}



int	count_letters(char *str, char c)
{
	int	num_letters;
	int	i;

	num_letters = 0;
	i = 0;
	if (!str)
		return(-1);
	while(str && str[i])
	{
		if (str[i++] == c)
		num_letters++;
	}
	return (num_letters);
}


static void	*ft_empty_line(char **lines, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
	return (NULL);
}

char	**map_dup(t_game *game)
{
	int		y;
	char	**copy;

	y = 0;
	copy = malloc(game->w_lines * sizeof(char *));
	while (y <= game->w_lines)
	{
		if (game->map->map[y] == NULL)
		{
			copy[y] = NULL; 
			break;
		}
		copy[y] = ft_strdup(game->map->map[y]);
		if (!copy[y])
			return (ft_empty_line(copy, y));
		y++;
	}
	return (copy);
}
