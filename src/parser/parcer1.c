/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:27:40 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:28:10 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	preparcer1(t_game *game)
{
	game->map_flag = 0;
	game->map_flag_n = 0;
	game->resolution.x_res = -1;
	game->resolution.y_res = -1;
	game->resolution.yes = 0;
	game->ceiling.r = -1;
	game->ceiling.g = -1;
	game->ceiling.b = -1;
	game->ceiling.yes = 0;
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->floor.yes = 0;
	game->north.no_path = NULL;
	game->south.so_path = NULL;
	game->west.we_path = NULL;
	game->east.ea_path = NULL;
}
