/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:17:27 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/02 18:52:15 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	player_where(char **map, int last_row, int max_len, t_game *game)
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
			if (ft_strchr("NSWE", map[i][j]))
			{
				player_angle(map, i, j, game);
				game->player.x = j * TILE_SIZE + 32;
				game->player.y = i * TILE_SIZE + 32;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	check_sprites_number(char **map, int last_row, int max_len,
t_game *game)
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
			if (ft_strchr("2", map[i][j]))
				game->num_sprites++;
			j++;
		}
		i++;
	}
}

void	sprite_parser(char **map, int last_row, int max_len, t_game *game)
{
	int i;
	int j;
	int num;

	i = 1;
	j = 1;
	num = 0;
	while (i < last_row)
	{
		j = 0;
		while (j < max_len)
		{
			if (ft_strchr("2", map[i][j]))
			{
				game->sprites[num].x = j * TILE_SIZE + 32;
				game->sprites[num].y = i * TILE_SIZE + 32;
				num++;
			}
			j++;
		}
		i++;
	}
}

void	map_final_validation(char **map, int last_row, int max_len,
t_game *game)
{
	check_borders_map(map, last_row, max_len);
	check_inner_map(map, last_row, max_len);
	check_player_number(map, last_row, max_len);
	player_where(map, last_row, max_len, game);
	check_sprites_number(map, last_row, max_len, game);
	check_every_inner_cell(map, last_row, max_len);
	game->sprites = (t_sprite *)malloc(sizeof(t_sprite) * game->num_sprites);
	sprite_parser(map, last_row, max_len, game);
}

char	**map_maker(t_list **head, t_game *game)
{
	t_list	*tmp;
	int		lst_size;
	int		max_len;
	char	**map;
	int		i;

	i = 0;
	list_n_killer(head);
	tmp = *head;
	max_len = max_len_content(head);
	lst_size = ft_lstsize(*head);
	if (!(map = (char **)malloc(sizeof(char *) * (lst_size + 1))))
		error(5);
	while (tmp)
	{
		map[i] = list_to_str(tmp->content, max_len);
		i++;
		tmp = tmp->next;
	}
	map[i] = NULL;
	list_free(head, lst_size);
	map_final_validation(map, i - 1, max_len - 1, game);
	game->map_num_rows = i;
	game->map_num_cols = max_len;
	return (map);
}
