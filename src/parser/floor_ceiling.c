/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:13:54 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/02 10:11:51 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ceiling_cycle(t_game *game, char *str, int *j)
{
	int	comma;
	int	i;

	comma = 0;
	i = *j;
	i = digits_through(str, i);
	i = space_through(str, i);
	if (game->ceiling.r > -1)
	{
		while (str[i] != '\0' && !(ft_isdigit(str[i])))
		{
			if (str[i] == ',')
				comma++;
			if (!ft_strchr(", 0123456789", str[i]))
				error(2);
			i++;
		}
		if (comma != 1)
			error(2);
	}
	*j = i;
	return (ft_atoi_cub(str + i));
}

int		floor_cycle(t_game *game, char *str, int *j)
{
	int comma;
	int i;

	comma = 0;
	i = *j;
	i = digits_through(str, i);
	i = space_through(str, i);
	if (game->floor.r > -1)
	{
		while (str[i] != '\0' && !(ft_isdigit(str[i])))
		{
			if (str[i] == ',')
				comma++;
			i++;
		}
		if (comma != 1)
			error(2);
	}
	*j = i;
	return (ft_atoi_cub(str + i));
}

void	parse_floor(t_game *game, char *str, int i)
{
	if (!game->floor.yes)
	{
		i++;
		if (str[i] != ' ')
			error(2);
		game->floor.r = floor_cycle(game, str, &i);
		game->floor.g = floor_cycle(game, str, &i);
		game->floor.b = floor_cycle(game, str, &i);
		i = digits_through(str, i);
		i = space_through(str, i);
		if (str[i] != '\0' || game->floor.r == -1 || game->floor.g == -1
		|| game->floor.b == -1 || game->floor.r > 255 || game->floor.g > 255
		|| game->floor.b > 255)
			error(2);
		else
			game->floor.yes = 1;
	}
	else
	{
		game->floor.yes = 0;
		error(2);
	}
}

void	parse_ceiling(t_game *game, char *str, int i)
{
	if (!game->ceiling.yes)
	{
		i++;
		if (str[i] != ' ')
			error(2);
		game->ceiling.r = ceiling_cycle(game, str, &i);
		game->ceiling.g = ceiling_cycle(game, str, &i);
		game->ceiling.b = ceiling_cycle(game, str, &i);
		i = digits_through(str, i);
		i = space_through(str, i);
		if (str[i] != '\0' || game->ceiling.r == -1 || game->ceiling.g == -1
		|| game->ceiling.b == -1 || game->ceiling.r > 255
		|| game->ceiling.g > 255 || game->ceiling.b > 255)
			error(2);
		else
			game->ceiling.yes = 1;
	}
	else
	{
		game->ceiling.yes = 0;
		error(2);
	}
}
