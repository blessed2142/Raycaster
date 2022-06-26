/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:09:19 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 02:09:22 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_help(int key, t_game *game)
{
	if (key == 1)
	{
		game->player.walkdirection = -1;
		game->player.sidedirection = 0;
	}
	if (key == 0)
	{
		game->player.sidedirection = 1;
		game->player.walkdirection = 1;
	}
	if (key == 2)
	{
		game->player.sidedirection = -1;
		game->player.walkdirection = 1;
	}
}

int		key_press(int key, t_game *game)
{
	if (key == 13)
		game->player.walkdirection = 1;
	else if (key == 46 && !game->minimap)
		game->minimap = 1;
	else if (key == 46 && game->minimap)
		game->minimap = 0;
	else if (key == 123)
		game->player.turndirection = -1;
	else if (key == 1)
		key_help(1, game);
	else if (key == 124)
		game->player.turndirection = 1;
	else if (key == 0)
		key_help(0, game);
	else if (key == 2)
		key_help(2, game);
	else if (key == 53)
		exit(0);
	return (0);
}

int		key_release(int key, t_game *game)
{
	if (key == 13)
		game->player.walkdirection = 0;
	else if (key == 123)
		game->player.turndirection = 0;
	else if (key == 0)
	{
		game->player.sidedirection = 0;
		game->player.walkdirection = 0;
	}
	else if (key == 2)
	{
		game->player.sidedirection = 0;
		game->player.walkdirection = 0;
	}
	else if (key == 1)
		game->player.walkdirection = 0;
	else if (key == 124)
		game->player.turndirection = 0;
	else if (key == 53)
		exit(0);
	return (0);
}

int		mlx_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}
