/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:10:24 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/17 11:42:42 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc < 1)
		return(0);
	create_map(&game, argv);
	parsing_init(&game);
	init_game(&game);
	//printf("Adios");
	return (0);
}
