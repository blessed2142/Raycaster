/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:14:48 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:14:49 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_draw_helper(t_game *game, t_sprite_help *sprite_help,
t_sprite_iter *iter, t_sprite_draw *sd)
{
	sd->distancefromtop = iter->y +
	(sprite_help->spriteheight / 2) - (game->resolution.y_res / 2);
	sd->textureoffsety = sd->distancefromtop *
	(sprite_help->textureheight / sprite_help->spriteheight);
	sd->spritetexturebuffer = game->texture[0];
	sd->texelcolor = sd->spritetexturebuffer[(sprite_help->texturewidth *
	sd->textureoffsety) + sd->textureoffsetx];
}

void	sprite_draw(t_game *game, t_sprite_help *sprite_help,
t_sprite_iter *iter, t_sprite *sprite)
{
	t_sprite_draw sd;

	while (iter->x < sprite_help->spriterightx)
	{
		sd.texelwidth = (sprite_help->texturewidth / sprite_help->spritewidth);
		sd.textureoffsetx = (iter->x - sprite_help->spriteleftx)
		* sd.texelwidth;
		iter->y = sprite_help->spritetopy;
		while (iter->y < sprite_help->spritebottomy)
		{
			if (iter->x > 0 && iter->x < game->resolution.x_res && iter->y > 0
			&& iter->y < game->resolution.y_res)
			{
				sprite_draw_helper(game, sprite_help, iter, &sd);
				if (sprite->distance <
				game->rays[iter->x].distance && sd.texelcolor != 0x00000000)
					drawpixel(game, iter->x, iter->y, sd.texelcolor);
			}
			iter->y++;
		}
		iter->x++;
	}
}

void	renderspriteprojection(t_game *game)
{
	t_sprite		*visiblesprites;
	t_sprite_help	sprite_help;
	t_sprite		sprite;
	t_sprite_iter	iter;

	iter_clear(&iter);
	if (!(visiblesprites = (t_sprite *)malloc(sizeof(t_sprite)
	* game->num_sprites)))
		error(5);
	iter.numvisiblesprites = visible_or_not(game, visiblesprites);
	sprite_sort(visiblesprites, iter.numvisiblesprites);
	while (iter.i < iter.numvisiblesprites)
	{
		sprite = visiblesprites[iter.i];
		sprite_calc(game, &sprite_help, &sprite);
		iter.x = sprite_help.spriteleftx;
		sprite_draw(game, &sprite_help, &iter, &sprite);
		iter.i++;
	}
	free(visiblesprites);
}
