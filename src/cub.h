/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:47:55 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 03:47:57 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include <stdint.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>

# define TILE_SIZE 64
# define TEXWIDTH TILE_SIZE
# define TEXHEIGHT TILE_SIZE
# define PI 3.14159265
# define TWO_PI 6.28318530
# define FOV_ANGLE (60 * (PI / 180))
# define MINIMAP_SCALE_FACTOR 0.1

typedef struct	s_resolution
{
	int	x_res;
	int	y_res;
	int	yes;
}				t_resolution;

typedef struct	s_north
{
	char			*no_path;
	int				yes;
}				t_north;

typedef struct	s_south
{
	char			*so_path;
	int				yes;
}				t_south;

typedef struct	s_east
{
	char			*ea_path;
	int				yes;
}				t_east;

typedef struct	s_west
{
	char			*we_path;
	int				yes;
}				t_west;

typedef	struct	s_floor
{
	int				r;
	int				g;
	int				b;
	int				yes;
}				t_floor;

typedef	struct	s_ceiling
{
	int				r;
	int				g;
	int				b;
	int				yes;
}				t_ceiling;

typedef	struct	s_cast
{
	int				foundhorzwallhit;
	float			horzwallhitx;
	float			horzwallhity;
	int				foundvertwallhit;
	float			vertwallhitx;
	float			vertwallhity;
	float			horzhitdistance;
	float			verthitdistance;
}				t_cast;

typedef	struct	s_stepinter
{
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	float			nexthorztouchx;
	float			nexthorztouchy;
	float			nextverttouchx;
	float			nextverttouchy;
	float			xtocheck;
	float			ytocheck;
}				t_stepinter;

typedef	struct	s_img
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}				t_img;

typedef	struct	s_player
{
	float			x;
	float			y;
	float			width;
	float			height;
	int				turndirection;
	int				walkdirection;
	int				sidedirection;
	float			rotationangle;
	float			walkspeed;
	float			turnspeed;
}				t_player;

typedef	struct	s_mapgrid
{
	int				mapgridindexx;
	int				mapgridindexy;
	int				mapgridindexx1;
	int				mapgridindexy1;
	int				mapgridindexx2;
	int				mapgridindexy2;
	int				mapgridindexx3;
	int				mapgridindexy3;
	int				mapgridindexx4;
	int				mapgridindexy4;
}				t_mapgrid;

typedef struct	s_sprite_iter
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				numvisiblesprites;
}				t_sprite_iter;

typedef struct	s_sprite
{
	float			x;
	float			y;
	float			distance;
	float			angle;
	int				visible;
}				t_sprite;

typedef	struct	s_sprite_help
{
	float			perpdistance;
	float			spriteheight;
	float			spritewidth;
	float			spritetopy;
	float			spritebottomy;
	float			spriteangle;
	float			spritescreenposx;
	float			spriteleftx;
	float			spriterightx;
	int				texturewidth;
	int				textureheight;
}				t_sprite_help;

typedef	struct	s_wall_draw
{
	float			perpdistance;
	float			wallheight;
	int				walltopy;
	int				wallbottomy;
	int				textureoffsetx;
	int				texturewidth;
	int				textureheight;
	int				texnum;
	int				distancefromtop;
	int				textureoffsety;
	int				*walltexturebuffer;
	int				texelcolor;
}				t_wall_draw;

typedef struct	s_sprite_draw
{
	float			texelwidth;
	int				textureoffsetx;
	int				distancefromtop;
	int				textureoffsety;
	int				*spritetexturebuffer;
	int				texelcolor;
}				t_sprite_draw;

typedef	struct	s_ray
{
	float			rayangle;
	float			wallhitx;
	float			wallhity;
	float			distance;
	int				washitvertical;
	int				texture;
	int				ray_face;
}				t_ray;

typedef	struct	s_screenshot
{
	char			*bmp;
	int				size;
	int				zero;
	int				offset;
	int				header;
	int				planes;
	int				bits_per_pixel;
	unsigned int	zero2;
	int				height;
}				t_screenshot;

typedef struct	s_game
{
	void			*mlx;
	void			*mlx_win;
	int				window_width;
	int				window_height;
	int				map_num_rows;
	int				map_num_cols;
	t_img			img;
	t_player		player;
	t_ray			*rays;
	t_sprite		*sprites;
	int				**texture;
	t_resolution	resolution;
	t_floor			floor;
	t_ceiling		ceiling;
	t_north			north;
	t_south			south;
	t_east			east;
	t_west			west;
	char			*sprite_texture;
	int				texture_yes;
	char			**map;
	int				minimap;
	int				map_flag;
	int				map_flag_n;
	int				num_sprites;
	double			dist_proj_plane;
}				t_game;

float			distancebetweenpoints(float x1, float y1, float x2, float y2);
int				maphaswallat(t_game *game, float x, float y);
int				isinsidemap(t_game *game, float x, float y);
void			drawpixel(t_game *game, int x, int y, unsigned int color);
int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);
void			rendermap(t_game *game);
void			normalizeangle(float *angle);
void			player_init(t_game *game);
void			renderplayer(t_game *game);
void			moveplayer(t_game *game);
void			window_init(t_game *game);
void			image_init(t_game *game);
int				israyfacingdown(float angle);
int				israyfacingup(float angle);
int				israyfacingright(float angle);
int				israyfacingleft(float angle);
void			castray(float rayangle, int stripid, t_game *game);
void			castallrays(t_game *game);
void			renderrays(t_game *game);
void			changecolorintensity(int *color, float factor);
void			renderwall(t_game *game);
void			rendermapsprites(t_game *game);
void			renderspriteprojection(t_game *game);
void			load_image(t_game *game, int *texture, char *path, t_img *img);
void			load_texture(t_game *game);
int				main_loop(t_game *game);
void			error(int error_code);
int				ceiling_cycle(t_game *game, char *str, int *j);
int				floor_cycle(t_game *game, char *str, int *j);
void			parse_floor(t_game *game, char *str, int i);
void			parse_ceiling(t_game *game, char *str, int i);
t_list			*ft_lstnew_dope(void *content);
void			ft_lstadd_back_dope(t_list **lst, t_list *new,
t_game *game, char *str);
int				max_len_content(t_list **head);
void			ft_lstclear_dope(t_list **lst, void (*del)(void *), char *str);
int				list_n_killer_help(char *str);
void			list_n_killer(t_list **head);
void			list_cleaner(t_list **head);
int				checklist(t_game *game, char *str);
char			*list_to_str(const char *str, int max_len);
void			list_free(t_list **head, int lst_size);
char			*cub_strjoin(char *s1, char *s2);
char			*space_str(int space_number);
void			check_borders_map_help(char **map, int stat, int flag);
void			check_borders_map(char **map, int last_row, int max_len);
void			check_inner_map(char **map, int last_row, int max_len);
void			check_player_number(char **map,
int last_row, int max_len);
void			player_where(char **map, int last_row,
int max_len, t_game *game);
void			check_item(char **map, int i, int j);
void			check_every_inner_cell(char **map, int last_row, int max_len);
void			map_final_validation(char **map, int last_row,
int				max_len, t_game *game);
char			**map_maker(t_list **head, t_game *game);
int				parser_help(char *str, int i);
void			parser(t_game *game, char *str);
void			preparcer(t_game *game);
int				yes(t_game *game);
void			parser_init(t_game *game, char *argv);
int				ft_atoi_cub(const char *str);
int				space_through(char *str, int i);
int				digits_through(char *str, int i);
void			parse_resol(t_game *game, char *str, int i);
char			*texture_cpy(char *str);
void			parse_north(t_game *game, char *str, int i);
void			parse_south(t_game *game, char *str, int i);
void			parse_west(t_game *game, char *str, int i);
void			parse_east(t_game *game, char *str, int i);
void			parse_sprite_texture(t_game *game, char *str, int i);
void			textures_malloc(t_game *game);
void			horz_intercept_handler(t_game *game,
t_stepinter *si, float rayangle);
void			horz_step_handler(t_game *game, t_stepinter *si,
float rayangle);
void			horz_wall_hit(t_game *game, t_cast *cast, float rayangle);
void			horz_hit_distance(t_game *game, t_cast *cast);
void			vert_intercept_handler(t_game *game,
t_stepinter *si, float rayangle);
void			vert_step_handler(t_game *game,
t_stepinter *si, float rayangle);
void			vert_wall_hit(t_game *game, t_cast *cast, float rayangle);
void			vert_hit_distance(t_game *game, t_cast *cast);
void			renderspriteprojection(t_game *game);
void			sprite_draw(t_game *game, t_sprite_help
*sprite_help, t_sprite_iter *iter, t_sprite *sprite);
void			iter_clear(t_sprite_iter *iter);
void			sprite_calc(t_game *game,
t_sprite_help *sprite_help, t_sprite *sprite);
int				visible_or_not(t_game *game, t_sprite *visiblesprites);
void			sprite_sort(t_sprite *visiblesprites, int numvisiblesprites);
int				mlx_close(t_game *game);
void			ft_screenshot(t_game *game);
void			ft_set_bmp(t_screenshot *bmp, t_game *game);
void			screen_maker(t_game *game);
void			preparcer1(t_game *game);
void			player_angle(char **map, int i, int j, t_game *game);
void			check_xpm(t_game *game);

#endif
