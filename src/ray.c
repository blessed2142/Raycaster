/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:15:21 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/03 16:22:54 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cast_null(t_cast *cast)
{
	cast->foundhorzwallhit = 0;
	cast->horzwallhitx = 0;
	cast->horzwallhity = 0;
	cast->foundvertwallhit = 0;
	cast->vertwallhitx = 0;
	cast->vertwallhity = 0;
	cast->horzhitdistance = 0;
	cast->verthitdistance = 0;
}

void	castray(float rayangle, int stripid, t_game *game)
{
	t_cast cast;

	cast_null(&cast);
	normalizeangle(&rayangle);
	horz_wall_hit(game, &cast, rayangle);
	vert_wall_hit(game, &cast, rayangle);
	horz_hit_distance(game, &cast);
	vert_hit_distance(game, &cast);
	if (cast.verthitdistance < cast.horzhitdistance)
	{
		game->rays[stripid].distance = cast.verthitdistance;
		game->rays[stripid].wallhitx = cast.vertwallhitx;
		game->rays[stripid].wallhity = cast.vertwallhity;
		game->rays[stripid].washitvertical = 1;
		game->rays[stripid].rayangle = rayangle;
	}
	else
	{
		game->rays[stripid].distance = cast.horzhitdistance;
		game->rays[stripid].wallhitx = cast.horzwallhitx;
		game->rays[stripid].wallhity = cast.horzwallhity;
		game->rays[stripid].washitvertical = 0;
		game->rays[stripid].rayangle = rayangle;
	}
}

void	castallrays(t_game *game)
{
	int		col;
	float	rayangle;

	col = 0;
	while (col < game->resolution.x_res)
	{
		rayangle = game->player.rotationangle +
		atan((col - game->resolution.x_res / 2) / game->dist_proj_plane);
		castray(rayangle, col, game);
		col++;
	}
}
