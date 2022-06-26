/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:08:45 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/02 11:00:14 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ft_atoi_cub(const char *str)
{
	int	i;
	int	res;
	int	z;

	i = 0;
	z = 1;
	res = 0;
	if (str[i] == '\0')
		return (-1);
	if (str[i] < 27 || (str[i] > 27 && str[i] < 33))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		return (-1);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (res * z);
}

int		space_through(char *str, int i)
{
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		return (i);
	}
	return (i);
}

int		digits_through(char *str, int i)
{
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
			i++;
		return (i);
	}
	return (i);
}

void	resol_compare(t_game *game)
{
	int c_width;
	int c_height;

	mlx_get_screen_size(&c_width, &c_height);
	game->resolution.x_res = game->resolution.x_res > c_width ?
	c_width : game->resolution.x_res;
	game->resolution.y_res = game->resolution.y_res > c_height ?
	c_height : game->resolution.y_res;
}

void	parse_resol(t_game *game, char *str, int i)
{
	if (!game->resolution.yes)
	{
		i++;
		if (str[i] != ' ')
			error(1);
		i = space_through(str, i);
		game->resolution.x_res = ft_atoi_cub(str + i);
		i = digits_through(str, i);
		i = space_through(str, i);
		game->resolution.y_res = ft_atoi_cub(str + i);
		i = digits_through(str, i);
		i = space_through(str, i);
		if (game->resolution.x_res <= 0 || game->resolution.y_res <= 0)
			error(1);
		else
			game->resolution.yes = 1;
		if (str[i] != '\0')
			error(1);
		resol_compare(game);
	}
	else
		error(1);
}
