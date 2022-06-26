/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:24:55 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:24:56 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_inner_map(char **map, int last_row, int max_len)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < last_row)
	{
		j = 0;
		while (j < max_len)
		{
			if (!ft_strchr("012NSWE ", map[i][j]))
				error(4);
			j++;
		}
		i++;
	}
}

void	check_player_number(char **map, int last_row, int max_len)
{
	int i;
	int j;
	int flag;

	i = 1;
	j = 1;
	flag = 0;
	while (i < last_row)
	{
		j = 0;
		while (j < max_len)
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (!flag)
					flag = 1;
				else
					error(4);
			}
			j++;
		}
		i++;
	}
	if (!flag)
		error(4);
}

void	check_item(char **map, int i, int j)
{
	char	*str;
	int		flag;

	str = "012NSWE";
	flag = 0;
	if (ft_strchr(str, map[i - 1][j - 1]) && ft_strchr(str, map[i - 1][j]))
	{
		if (ft_strchr(str, map[i - 1][j + 1]) && ft_strchr(str, map[i][j - 1]))
		{
			if ((ft_strchr(str, map[i][j + 1])))
			{
				if (ft_strchr(str, map[i + 1][j - 1]))
				{
					if ((ft_strchr(str, map[i + 1][j])))
					{
						if (ft_strchr(str, map[i + 1][j + 1]))
							flag = 1;
					}
				}
			}
		}
	}
	if (flag == 0)
		error(4);
}

void	check_every_inner_cell(char **map, int last_row, int max_len)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < last_row)
	{
		j = 0;
		while (j < max_len)
		{
			if (ft_strchr("02NSWE", map[i][j]))
				check_item(map, i, j);
			j++;
		}
		i++;
	}
}

void	player_angle(char **map, int i, int j, t_game *game)
{
	if (map[i][j] == 'N')
		game->player.rotationangle = PI / 2;
	else if (map[i][j] == 'S')
		game->player.rotationangle = 3 * (PI / 2);
	else if (map[i][j] == 'W')
		game->player.rotationangle = PI;
	else if (map[i][j] == 'E')
		game->player.rotationangle = PI * 2;
}
