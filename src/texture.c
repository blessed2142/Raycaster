/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:29:52 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:29:53 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	textures_malloc(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(game->texture = (int **)malloc(sizeof(int *) * 5)))
		error(5);
	while (i < 5)
	{
		if (!(game->texture[i] =
		(int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH))))
			error(5);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TEXHEIGHT * TEXWIDTH)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(game->mlx, path,
	&img->img_width, &img->img_height);
	img->addr = (unsigned int *)mlx_get_data_addr(img->img, &img->bpp,
	&img->line_length, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->addr[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	load_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->texture[0], game->sprite_texture, &img);
	load_image(game, game->texture[1], game->north.no_path, &img);
	load_image(game, game->texture[2], game->south.so_path, &img);
	load_image(game, game->texture[3], game->west.we_path, &img);
	load_image(game, game->texture[4], game->east.ea_path, &img);
}
