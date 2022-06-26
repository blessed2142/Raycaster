/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:15:23 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/01 22:24:54 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*texture_cpy(char *str)
{
	char *ret;

	if (!str)
		error(3);
	ret = ft_strdup(str);
	if (!ret)
		error(3);
	return (ret);
}

void	parse_north(t_game *game, char *str, int i)
{
	int fd;

	if (!game->north.yes)
	{
		i++;
		if (str[i] != ' ')
			error(3);
		i = space_through(str, i);
		game->north.no_path = texture_cpy(str + i);
		if ((fd = open(game->north.no_path, O_RDONLY)) < 0)
			error(3);
		close(fd);
		game->north.yes = 1;
	}
	else
		error(3);
}

void	parse_south(t_game *game, char *str, int i)
{
	int fd;

	if (!game->south.yes)
	{
		i++;
		if (str[i] != ' ')
			error(3);
		i = space_through(str, i);
		game->south.so_path = texture_cpy(str + i);
		if ((fd = open(game->south.so_path, O_RDONLY)) < 0)
			error(3);
		close(fd);
		game->south.yes = 1;
	}
	else
		error(3);
}

void	parse_west(t_game *game, char *str, int i)
{
	int fd;

	if (!game->west.yes)
	{
		i++;
		if (str[i] != ' ')
			error(3);
		i = space_through(str, i);
		game->west.we_path = texture_cpy(str + i);
		if ((fd = open(game->west.we_path, O_RDONLY)) < 0)
			error(3);
		close(fd);
		game->west.yes = 1;
	}
	else
		error(3);
}

void	parse_east(t_game *game, char *str, int i)
{
	int fd;

	if (!game->east.yes)
	{
		i++;
		if (str[i] != ' ')
			error(3);
		i = space_through(str, i);
		game->east.ea_path = texture_cpy(str + i);
		if ((fd = open(game->east.ea_path, O_RDONLY)) < 0)
			error(3);
		close(fd);
		game->east.yes = 1;
	}
	else
		error(3);
}
