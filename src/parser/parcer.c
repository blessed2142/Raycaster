/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:27:33 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:27:34 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		parser_help(char *str, int i)
{
	if (str[i] != '\0')
	{
		if (ft_strchr("012NSWE", str[i]))
		{
			if (!ft_strchr("OEA ", str[i + 1]))
				return (1);
		}
	}
	return (0);
}

void	parser(t_game *game, char *str)
{
	int i;

	i = 0;
	i = space_through(str, i);
	if (str[i] == 'R')
		parse_resol(game, str, i);
	else if (str[i] == 'F')
		parse_floor(game, str, i);
	else if (str[i] == 'C')
		parse_ceiling(game, str, i);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		parse_north(game, str, i + 1);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		parse_south(game, str, i + 1);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		parse_west(game, str, i + 1);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		parse_east(game, str, i + 1);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		parse_sprite_texture(game, str, i);
	else if (!yes(game) && parser_help(str, i))
		error(6);
	free(str);
}

void	preparcer(t_game *game)
{
	preparcer1(game);
	game->north.yes = 0;
	game->south.yes = 0;
	game->west.yes = 0;
	game->east.yes = 0;
	game->texture_yes = 0;
	game->player.walkdirection = 0;
	game->player.sidedirection = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->player.rotationangle = -1;
	game->num_sprites = 0;
}

int		yes(t_game *game)
{
	if (game->resolution.yes && game->floor.yes && game->ceiling.yes)
	{
		if (game->north.yes && game->south.yes && game->west.yes)
		{
			if (game->east.yes && game->texture_yes)
				return (1);
		}
	}
	return (0);
}

void	parser_init(t_game *game, char *argv)
{
	int		fd;
	int		flag;
	int		flag1;
	char	*str;
	t_list	*head;

	flag = 0;
	flag1 = 0;
	head = NULL;
	preparcer(game);
	fd = open(argv, O_RDONLY);
	while (!yes(game) && (get_next_line(fd, &str)))
		parser(game, str);
	while (get_next_line(fd, &str) && yes(game))
	{
		flag = 1;
		if (checklist(game, str) == 1)
			ft_lstadd_back_dope(&head, ft_lstnew_dope(str), game, str);
	}
	if (!flag)
		error(4);
	ft_lstadd_back_dope(&head, ft_lstnew_dope(str), game, str);
	close(fd);
	game->map = map_maker(&head, game);
}
