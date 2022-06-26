SRCS	=	./src/parser/floor_ceiling.c \
			./src/parser/list.c \
			./src/parser/list1.c \
			./src/parser/map_parser.c \
			./src/parser/map_parser1.c \
			./src/parser/map_parser2.c \
			./src/parser/parcer.c \
			./src/parser/parcer1.c \
			./src/parser/parse_resol.c \
			./src/parser/textures.c \
			./src/parser/textures1.c \
			./src/draw.c \
			./src/errors.c \
			./src/key.c \
			./src/main.c \
			./src/map.c \
			./src/player.c \
			./src/ray.c \
			./src/ray1.c \
			./src/ray2.c \
			./src/ray3.c \
			./src/screenshot.c \
			./src/sprite.c \
			./src/sprite1.c \
			./src/texture.c \
			./src/utils.c \
			./src/wall.c \
			./src/get_next_line/get_next_line.c \
			./src/get_next_line/get_next_line_utils.c \

OBJS	= 	$(SRCS:.c=.o)

LIBFT	=	./src/libft/libft.a

MLX 	=	./mlx/libmlx.a

NAME	=	cub3D

GCC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c		
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):	$(MLX) $(OBJS) $(LIBFT) ./src/cub.h
			$(GCC) ./mlx/libmlx.a -framework OpenGL -framework AppKit $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):	
			make -C "./src/libft"

$(MLX):     
			make -C "mlx"

clean:		
			$(RM) $(OBJS)
			make clean -C "./src/libft"
			# make clean -C "./mlx/mlx"

fclean:		clean
			$(RM) $(NAME)  screenshot.bmp
			make fclean -C "./src/libft"
			make clean -C "mlx"

re:			fclean all

.PHONY:		all clean fclean re
