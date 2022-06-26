/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:21:21 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 02:21:23 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_init(t_game *game)
{
	game->player.width = 1;
	game->player.height = 1;
	game->player.turndirection = 0;
	game->player.walkdirection = 0;
	game->player.sidedirection = 0;
	game->player.walkspeed = 3;
	game->player.turnspeed = 3 * (PI / 180);
}

void	map_grinder(t_mapgrid *mapgrid, float x, float y)
{
	mapgrid->mapgridindexx = floor(x / TILE_SIZE);
	mapgrid->mapgridindexy = floor(y / TILE_SIZE);
	mapgrid->mapgridindexx1 = floor((x + 1) / TILE_SIZE);
	mapgrid->mapgridindexy1 = floor((y + 1) / TILE_SIZE);
	mapgrid->mapgridindexx2 = floor((x - 1) / TILE_SIZE);
	mapgrid->mapgridindexy2 = floor((y - 1) / TILE_SIZE);
	mapgrid->mapgridindexx3 = floor((x + 2) / TILE_SIZE);
	mapgrid->mapgridindexy3 = floor((y + 2) / TILE_SIZE);
	mapgrid->mapgridindexx4 = floor((x - 2) / TILE_SIZE);
	mapgrid->mapgridindexy4 = floor((y - 2) / TILE_SIZE);
}

int		maphaswallat_move(t_game *game, float x, float y)
{
	t_mapgrid mapgrid;

	if (x < 0 || x > game->map_num_cols * TILE_SIZE
	|| y < 0 || y > game->map_num_rows * TILE_SIZE)
		return (1);
	map_grinder(&mapgrid, x, y);
	if (game->map[mapgrid.mapgridindexy][mapgrid.mapgridindexx] == '1'
	|| game->map[mapgrid.mapgridindexy1][mapgrid.mapgridindexx1] == '1'
	|| game->map[mapgrid.mapgridindexy2][mapgrid.mapgridindexx2] == '1'
	|| game->map[mapgrid.mapgridindexy3][mapgrid.mapgridindexx3] == '1'
	|| game->map[mapgrid.mapgridindexy4][mapgrid.mapgridindexx4] == '1')
		return (1);
	else
		return (0);
}

void	new_player_calc(t_game *game, float *newplayerx, float *newplayery)
{
	float movestep;

	movestep = game->player.walkdirection * game->player.walkspeed;
	if (game->player.sidedirection == 0)
	{
		*newplayerx = game->player.x + cos(game->player.rotationangle)
		* movestep;
		*newplayery = game->player.y + sin(game->player.rotationangle)
		* movestep;
	}
	else if (game->player.sidedirection == 1)
	{
		*newplayerx = game->player.x + cos(game->player.rotationangle
		- (PI / 2)) * movestep;
		*newplayery = game->player.y + sin(game->player.rotationangle
		- (PI / 2)) * movestep;
	}
	else if (game->player.sidedirection == -1)
	{
		*newplayerx = game->player.x + cos(game->player.rotationangle
		+ (PI / 2)) * movestep;
		*newplayery = game->player.y + sin(game->player.rotationangle
		+ (PI / 2)) * movestep;
	}
}

void	moveplayer(t_game *game)
{
	float newplayerx;
	float newplayery;

	newplayerx = 0.0;
	newplayery = 0.0;
	game->player.rotationangle += game->player.turndirection
	* game->player.turnspeed;
	normalizeangle(&game->player.rotationangle);
	new_player_calc(game, &newplayerx, &newplayery);
	if (!maphaswallat_move(game, newplayerx, newplayery))
	{
		game->player.x = newplayerx;
		game->player.y = newplayery;
	}
}
