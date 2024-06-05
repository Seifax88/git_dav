/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:08:01 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/31 11:37:13 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	parsing_init(t_game *game)
{
	char	**test;
	int		y;
	
	check_map_empty(game);
	check_map_borders(game);
	check_map_content(game);
	test = map_dup(game);
	flood_fill(test);
	y = 0;
	while (test[y] != NULL)
	{
		free(test[y]);
		y++;
	}
	free(test);
	test = NULL;
}
