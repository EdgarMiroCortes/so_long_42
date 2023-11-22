NAME		=	../so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	../libft/libft.a
INC			=	-I ../inc -I ../libft -I ../mlx
LIB			=	-L ../libft -L../mlx -l../mlx -framework OpenGL -framework AppKit
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	../src/so_long.c\
				../src/read.c\
				../src/set_sizes.c\
				../src/check_sol.c\
				../src/moves.c\
				../src/check_map.c\
				../src/mlx_utils.c

all:		$(MLX) makelib obj $(NAME)

$(NAME):	$(OBJ) 
			$(CC) $(FLAGS) $(LIB) $(OBJ) $(LFT) -o $@

# -fsanitize=address

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C ../mlx
			@echo " [ OK ] | Minilibx ready!"

makelib:		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C ../libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p ../obj

../obj/%.o:	src/%.c Makefile ../src/so_long.h
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) ../obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C ../libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re