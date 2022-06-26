/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:00:46 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:00:48 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	screen_maker(t_game *game)
{
	castallrays(game);
	renderwall(game);
	renderspriteprojection(game);
	ft_screenshot(game);
	exit(0);
}

void	ft_set_bmp(t_screenshot *bmp, t_game *game)
{
	bmp->bmp = "BM";
	bmp->size = game->resolution.x_res * game->resolution.y_res * 32 / 8 + 54;
	bmp->zero = 0;
	bmp->offset = 54;
	bmp->header = 40;
	bmp->planes = 1;
	bmp->bits_per_pixel = game->img.bpp;
	bmp->zero2 = 0;
	bmp->height = -game->resolution.y_res;
}

void	ft_screenshot(t_game *game)
{
	int				fd;
	t_screenshot	bmp;

	ft_set_bmp(&bmp, game);
	fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IREAD | S_IWUSR);
	if (fd < 0)
		printf("Error\nScreenshot create file failed\n");
	write(fd, bmp.bmp, 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.zero, 4);
	write(fd, &bmp.offset, 4);
	write(fd, &bmp.header, 4);
	write(fd, &game->resolution.x_res, 4);
	write(fd, &bmp.height, 4);
	write(fd, &bmp.planes, 2);
	write(fd, &bmp.bits_per_pixel, 2);
	write(fd, &bmp.zero2, 24);
	write(fd, game->img.addr, game->resolution.x_res
	* game->resolution.y_res * 32 / 8);
	close(fd);
}
