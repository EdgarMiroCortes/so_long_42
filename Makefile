NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c\
				src/read.c\

all:		$(MLX) makelib obj $(NAME)

$(NAME):	$(OBJ) Makefile
			$(CC) $(FLAGS) $(LIB) $(OBJ) $(LFT) -o $@

# -fsanitize=address

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

makelib:		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re