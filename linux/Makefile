NAME		=	../so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	../libft/libft.a
INC			=	-I ../inc -I ../libft -I ../mlx
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	../src/so_long.c\
				../src/read.c\
				../src/set_sizes.c\
				../src/check_sol.c\
				../src/moves.c\
				../src/check_map.c\
				../src/mlx_utils.c

all:		makemlx makelib obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# -fsanitize=address

makemlx:
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C ../mlx_linux
			@echo " [ OK ] | Minilibx ready!"

makelib:		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C ../libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p ../obj

../obj/%.o: %.c Makefile ../src/so_long.h
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
			@make -s $@ -C ../libft
			@rm -rf $(OBJ) ../obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C ../libft
			@rm -rf ../$(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re