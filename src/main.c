/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:33:43 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/03 12:33:46 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
	game->resolution.x_res,
	game->resolution.y_res, "cub3D");
}

void	image_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,
	game->resolution.x_res, game->resolution.y_res);
	game->img.addr = (unsigned int *)mlx_get_data_addr(game->img.img,
	&game->img.bpp,
	&game->img.line_length,
	&game->img.endian);
}

int		main_loop(t_game *game)
{
	castallrays(game);
	renderwall(game);
	renderspriteprojection(game);
	moveplayer(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

void	check_args(int argc, char **argv)
{
	int len;
	int fd;

	if ((fd = open(argv[1], O_RDONLY) < 0) || read(fd, NULL, 0) == -1)
		error(7);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + len, 4))
		error(7);
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 6) || ft_strlen(argv[2]) != 6)
			error(7);
	}
}

int		main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 || argc == 3)
	{
		check_args(argc, argv);
		parser_init(&game, argv[1]);
	}
	else
		error(7);
	check_xpm(&game);
	window_init(&game);
	image_init(&game);
	textures_malloc(&game);
	load_texture(&game);
	game.rays = (t_ray *)malloc(sizeof(t_ray) * game.resolution.x_res + 1);
	game.dist_proj_plane = ((game.resolution.x_res / 2) / tan(FOV_ANGLE / 2));
	player_init(&game);
	if (argc == 3)
		screen_maker(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_hook(game.mlx_win, 2, 0, &key_press, &game);
	mlx_hook(game.mlx_win, 3, 0, &key_release, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, &mlx_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
