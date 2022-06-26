/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:42:25 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:42:26 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				texture_calc(t_game *game, int x)
{
	if ((game->rays[x].rayangle > 1.5 * PI ||
	game->rays[x].rayangle < 0.5 * PI) && game->rays[x].washitvertical)
		return (4);
	else if ((game->rays[x].rayangle < 1.5 * PI
	|| game->rays[x].rayangle > 0.5 * PI) && game->rays[x].washitvertical)
		return (3);
	else if ((game->rays[x].rayangle > 1.0 * PI
	&& game->rays[x].rayangle < 2.0 * PI) && !game->rays[x].washitvertical)
	{
		return (2);
	}
	else if ((game->rays[x].rayangle < 1.0 * PI &&
	game->rays[x].rayangle > 0.0 * PI) && !game->rays[x].washitvertical)
	{
		return (1);
	}
	return (1);
}

unsigned int	color_calc(t_game *game, int flag)
{
	if (flag)
	{
		return (((256 * 256) * game->ceiling.r) +
		(256 * game->ceiling.g) + game->ceiling.b);
	}
	if (!flag)
	{
		return (((256 * 256) * game->floor.r) +
		(256 * game->floor.g) + game->floor.b);
	}
	return (228);
}

int				render_wall_help(t_game *game, t_wall_draw *wall, int x, int y)
{
	wall->perpdistance = game->rays[x].distance *
	cos(game->rays[x].rayangle - game->player.rotationangle);
	wall->wallheight = (TILE_SIZE / wall->perpdistance)
	* game->dist_proj_plane;
	wall->walltopy = (game->resolution.y_res / 2)
	- (wall->wallheight / 2);
	wall->walltopy = wall->walltopy < 0 ? 0 : wall->walltopy;
	wall->wallbottomy = (game->resolution.y_res / 2)
	+ (wall->wallheight / 2);
	wall->wallbottomy = wall->wallbottomy > game->resolution.y_res
	? game->resolution.y_res : wall->wallbottomy;
	while (y < wall->walltopy)
	{
		drawpixel(game, x, y, color_calc(game, 1));
		y++;
	}
	return (y);
}

int				render_wall_help_2(t_game *game,
t_wall_draw *wall, int x, int y)
{
	while (y < wall->wallbottomy)
	{
		wall->distancefromtop = y + (wall->wallheight / 2)
		- (game->resolution.y_res / 2);
		wall->textureoffsety = wall->distancefromtop
		* ((float)wall->textureheight / wall->wallheight);
		wall->walltexturebuffer = game->texture[wall->texnum];
		wall->texelcolor = wall->walltexturebuffer[(wall->texturewidth
		* wall->textureoffsety) + wall->textureoffsetx];
		drawpixel(game, x, y, wall->texelcolor);
		y++;
	}
	y = wall->wallbottomy;
	while (y < game->resolution.y_res)
	{
		drawpixel(game, x, y, color_calc(game, 0));
		y++;
	}
	return (y);
}

void			renderwall(t_game *game)
{
	int				x;
	int				y;
	t_wall_draw		wd;

	x = 0;
	while (x < game->resolution.x_res)
	{
		y = 0;
		y = render_wall_help(game, &wd, x, y);
		if (game->rays[x].washitvertical)
			wd.textureoffsetx = (int)game->rays[x].wallhity % TILE_SIZE;
		else
			wd.textureoffsetx = (int)game->rays[x].wallhitx % TILE_SIZE;
		wd.texnum = texture_calc(game, x);
		wd.texturewidth = TEXWIDTH;
		wd.textureheight = TEXHEIGHT;
		y = wd.walltopy;
		y = render_wall_help_2(game, &wd, x, y);
		x++;
	}
}
