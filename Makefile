NAME = fractal
LIB = libft/libftprintf.a
MLX = libft/libmlx.a
INCL = fdfHeader.h
FLAGS = #-Wall -Wextra -Werror
SRC =     ./src/main.c\
			./src/mald.c\
			./src/mess_err.c\
			./src/img_operation.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(SRC) $(LIB) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

$(LIB):
	@make -C libft

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -I $(INCL) -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all