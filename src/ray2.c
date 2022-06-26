/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:44:23 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 02:44:25 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	horz_intercept_handler(t_game *game, t_stepinter *si, float rayangle)
{
	si->yintercept = floor(game->player.y / TILE_SIZE) * TILE_SIZE;
	si->yintercept += israyfacingdown(rayangle) ? TILE_SIZE : 0;
	si->xintercept = game->player.x + (si->yintercept - game->player.y)
	/ tan(rayangle);
}

void	horz_step_handler(t_game *game, t_stepinter *si, float rayangle)
{
	(void)game;
	si->ystep = TILE_SIZE;
	si->ystep *= israyfacingup(rayangle) ? -1 : 1;
	si->xstep = TILE_SIZE / tan(rayangle);
	si->xstep *= (israyfacingleft(rayangle) && si->xstep > 0) ? -1 : 1;
	si->xstep *= (israyfacingright(rayangle) && si->xstep < 0) ? -1 : 1;
}

void	horz_wall_hit(t_game *game, t_cast *cast, float rayangle)
{
	t_stepinter si;

	horz_intercept_handler(game, &si, rayangle);
	horz_step_handler(game, &si, rayangle);
	si.nexthorztouchx = si.xintercept;
	si.nexthorztouchy = si.yintercept;
	while (isinsidemap(game, si.nexthorztouchx, si.nexthorztouchy))
	{
		si.xtocheck = si.nexthorztouchx;
		si.ytocheck = si.nexthorztouchy + (israyfacingup(rayangle) ? -1 : 0);
		if (maphaswallat(game, si.xtocheck, si.ytocheck))
		{
			cast->horzwallhitx = si.nexthorztouchx;
			cast->horzwallhity = si.nexthorztouchy;
			cast->foundhorzwallhit = 1;
			break ;
		}
		else
		{
			si.nexthorztouchx += si.xstep;
			si.nexthorztouchy += si.ystep;
		}
	}
}

void	horz_hit_distance(t_game *game, t_cast *cast)
{
	cast->horzhitdistance = cast->foundhorzwallhit
		? distancebetweenpoints(game->player.x,
		game->player.y,
		cast->horzwallhitx, cast->horzwallhity)
		: FLT_MAX;
}
