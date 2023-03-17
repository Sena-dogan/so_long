CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./mlx -g
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c	readmap.c	mapcontrol.c	rendermap.c	move_player.c valid_path.c	
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -sC ./ft_printf/libft
	make -sC ./ft_printf
	make -sC ./mlx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc -g $(OBJS) $(GNLOBJS) $(LFLAGS) ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./mlx
	make clean -C ./ft_printf/libft
	make clean -C ./ft_printf
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./mlx
	make fclean -C ./ft_printf/libft
	make fclean -C ./ft_printf

norm:
	norminette ./*.c

run: all
	./so_long maps/map1.ber

re : fclean all

skyline:
	@clear
	@echo "__ / ____ I ____ I ____ \\ __"
	@echo "(⭕⭕ \\ ...SKYLINE.../ ⭕⭕)"
	@echo "(\\ __ / ____________ \\ __ /)"
	@echo "I_Oo_I ____.......____l_oO_|"
	@echo 

.PHONY: clean fclean re norm skyline
