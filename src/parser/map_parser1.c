/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:24:50 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:24:51 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*cub_strjoin(char *s1, char *s2)
{
	char	*dd;
	int		i;
	int		j;
	int		sl1;
	int		sl2;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	sl1 = ft_strlen_g(s1);
	sl2 = ft_strlen_g(s2);
	if (!(dd = (char *)malloc(sizeof(char) * (sl1 + sl2 + 1))))
		return (NULL);
	while (++i < sl1)
		dd[i] = s1[i];
	while (j < sl2)
		dd[i++] = s2[j++];
	dd[i] = '\0';
	free(s1);
	free(s2);
	return (dd);
}

char	*space_str(int space_number)
{
	char	*str;
	char	space;
	int		i;

	i = 0;
	space = ' ';
	if (space_number < 1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (space_number + 1))))
		return (NULL);
	while (i < space_number)
	{
		str[i] = space;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	check_borders_map_help(char **map, int stat, int flag)
{
	int i;

	i = 0;
	if (!flag)
	{
		while (map[stat][i] != '\0')
		{
			if (!(ft_strchr("1 ", map[stat][i])))
				error(4);
			i++;
		}
	}
	else
	{
		while (map[i])
		{
			if (!(ft_strchr("1 ", map[i][stat])))
				error(4);
			i++;
		}
	}
}

void	check_borders_map(char **map, int last_row, int max_len)
{
	check_borders_map_help(map, 0, 0);
	check_borders_map_help(map, last_row, 0);
	check_borders_map_help(map, 0, 1);
	check_borders_map_help(map, max_len, 1);
}
