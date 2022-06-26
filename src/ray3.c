/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:23:13 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/03 16:23:15 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vert_intercept_handler(t_game *game, t_stepinter *si, float rayangle)
{
	si->xintercept = floor(game->player.x / TILE_SIZE) * TILE_SIZE;
	si->xintercept += israyfacingright(rayangle) ? TILE_SIZE : 0;
	si->yintercept = game->player.y
	+ (si->xintercept - game->player.x) * tan(rayangle);
}

void	vert_step_handler(t_game *game, t_stepinter *si, float rayangle)
{
	(void)game;
	si->xstep = TILE_SIZE;
	si->xstep *= israyfacingleft(rayangle) ? -1 : 1;
	si->ystep = TILE_SIZE * tan(rayangle);
	si->ystep *= (israyfacingup(rayangle) && si->ystep > 0) ? -1 : 1;
	si->ystep *= (israyfacingdown(rayangle) && si->ystep < 0) ? -1 : 1;
}

void	vert_wall_hit(t_game *game, t_cast *cast, float rayangle)
{
	t_stepinter si;

	vert_intercept_handler(game, &si, rayangle);
	vert_step_handler(game, &si, rayangle);
	si.nextverttouchx = si.xintercept;
	si.nextverttouchy = si.yintercept;
	while (isinsidemap(game, si.nextverttouchx, si.nextverttouchy))
	{
		si.xtocheck = si.nextverttouchx + (israyfacingleft(rayangle) ? -1 : 0);
		si.ytocheck = si.nextverttouchy;
		if (maphaswallat(game, si.xtocheck, si.ytocheck))
		{
			cast->vertwallhitx = si.nextverttouchx;
			cast->vertwallhity = si.nextverttouchy;
			cast->foundvertwallhit = 1;
			break ;
		}
		else
		{
			si.nextverttouchx += si.xstep;
			si.nextverttouchy += si.ystep;
		}
	}
}

void	vert_hit_distance(t_game *game, t_cast *cast)
{
	cast->verthitdistance = cast->foundvertwallhit
		? distancebetweenpoints(game->player.x,
		game->player.y,
		cast->vertwallhitx, cast->vertwallhity)
		: FLT_MAX;
}
