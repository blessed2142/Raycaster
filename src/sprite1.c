/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:19:49 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:26:49 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_sort(t_sprite *visiblesprites, int numvisiblesprites)
{
	t_sprite	temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < numvisiblesprites - 1)
	{
		j = i + 1;
		while (j < numvisiblesprites)
		{
			if (visiblesprites[i].distance < visiblesprites[j].distance)
			{
				temp = visiblesprites[i];
				visiblesprites[i] = visiblesprites[j];
				visiblesprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	angle_calc(t_game *game, float *anglespriteplayer, int i)
{
	*anglespriteplayer = game->player.rotationangle - atan2(
	game->sprites[i].y - game->player.y, game->sprites[i].x - game->player.x);
	if (*anglespriteplayer > PI)
		*anglespriteplayer -= TWO_PI;
	if (*anglespriteplayer < -PI)
		*anglespriteplayer += TWO_PI;
	*anglespriteplayer = fabs(*anglespriteplayer);
}

int		visible_or_not(t_game *game, t_sprite *visiblesprites)
{
	int		i;
	int		numvisiblesprites;
	float	epsilon;
	float	anglespriteplayer;

	i = -1;
	numvisiblesprites = 0;
	epsilon = 0.2;
	while (++i < game->num_sprites)
	{
		angle_calc(game, &anglespriteplayer, i);
		if (anglespriteplayer < (FOV_ANGLE / 2) + epsilon)
		{
			game->sprites[i].visible = 1;
			game->sprites[i].angle = anglespriteplayer;
			game->sprites[i].distance = distancebetweenpoints(
			game->sprites[i].x,
			game->sprites[i].y, game->player.x, game->player.y);
			visiblesprites[numvisiblesprites] = game->sprites[i];
			numvisiblesprites++;
		}
		else
			game->sprites[i].visible = 0;
	}
	return (numvisiblesprites);
}

void	sprite_calc(t_game *game, t_sprite_help *sprite_help, t_sprite *sprite)
{
	sprite_help->perpdistance = sprite->distance * cos(sprite->angle);
	sprite_help->spriteheight = (TILE_SIZE /
	sprite_help->perpdistance) * game->dist_proj_plane;
	sprite_help->spritewidth = sprite_help->spriteheight;
	sprite_help->spritetopy = (game->resolution.y_res / 2)
	- (sprite_help->spriteheight / 2);
	sprite_help->spritetopy = (sprite_help->spritetopy < 0)
	? 0 : sprite_help->spritetopy;
	sprite_help->spritebottomy = (game->resolution.y_res / 2)
	+ (sprite_help->spriteheight / 2);
	sprite_help->spritebottomy = (sprite_help->spritebottomy
	> game->resolution.y_res) ? game->resolution.y_res :
	sprite_help->spritebottomy;
	sprite_help->spriteangle = atan2(sprite->y - game->player.y,
	sprite->x - game->player.x) - game->player.rotationangle;
	sprite_help->spritescreenposx = tan(sprite_help->spriteangle)
	* game->dist_proj_plane;
	sprite_help->spriteleftx = (game->resolution.x_res / 2)
	+ sprite_help->spritescreenposx - (sprite_help->spritewidth / 2);
	sprite_help->spriterightx = sprite_help->spriteleftx
	+ sprite_help->spritewidth;
	sprite_help->texturewidth = TEXWIDTH;
	sprite_help->textureheight = TEXHEIGHT;
}

void	iter_clear(t_sprite_iter *iter)
{
	iter->i = 0;
	iter->j = 0;
	iter->x = 0;
	iter->y = 0;
}
