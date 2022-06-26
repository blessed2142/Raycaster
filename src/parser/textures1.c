/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:16:58 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/02 18:08:26 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_xpm(t_game *game)
{
	if (ft_strncmp(game->north.no_path
	+ ft_strlen(game->north.no_path) - 4, ".xpm", 4))
		error(8);
	if (ft_strncmp(game->south.so_path
	+ ft_strlen(game->south.so_path) - 4, ".xpm", 4))
		error(8);
	if (ft_strncmp(game->west.we_path
	+ ft_strlen(game->west.we_path) - 4, ".xpm", 4))
		error(8);
	if (ft_strncmp(game->east.ea_path
	+ ft_strlen(game->east.ea_path) - 4, ".xpm", 4))
		error(8);
	if (ft_strncmp(game->sprite_texture
	+ ft_strlen(game->sprite_texture) - 4, ".xpm", 4))
		error(8);
}

void	parse_sprite_texture(t_game *game, char *str, int i)
{
	int fd;

	if (!game->texture_yes)
	{
		i++;
		if (str[i] != ' ')
			error(3);
		i = space_through(str, i);
		game->sprite_texture = texture_cpy(str + i);
		if ((fd = open(game->sprite_texture, O_RDONLY)) < 0)
			error(3);
		close(fd);
		game->texture_yes = 1;
	}
	else
		error(3);
}
