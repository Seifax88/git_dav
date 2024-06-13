/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:10:24 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/13 08:57:11 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return(0);
	create_map(&game, argv);
	parsing_init(&game);
	init_game(&game);
	return (0);
}