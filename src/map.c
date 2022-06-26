/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:13:42 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 02:13:46 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		maphaswallat(t_game *game, float x, float y)
{
	int mapgridindex_x;
	int mapgridindex_y;

	if (x < 0 || x > game->map_num_cols * TILE_SIZE
	|| y < 0 || y > game->map_num_rows * TILE_SIZE)
		return (1);
	mapgridindex_x = floor(x / TILE_SIZE);
	mapgridindex_y = floor(y / TILE_SIZE);
	if (game->map[mapgridindex_y][mapgridindex_x] == '1')
		return (1);
	else
		return (0);
}

int		isinsidemap(t_game *game, float x, float y)
{
	return (x > 0 && x < game->map_num_cols * TILE_SIZE
	&& y > 0 && y < game->map_num_rows * TILE_SIZE);
}
