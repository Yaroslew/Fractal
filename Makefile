NAME = fractal
LIB = libft/libftprintf.a
MLX = libft/libmlx.a
INCL = fractal.h
#FLAGS = -Wall -Wextra -Werror
SRC =     ./src/main.c\
			./src/mandelbrot.c\
			./src/mess_err.c\
			./src/init.c\
			./src/check.c\
			./src/img_operation.c\
			./src/julia.c\
			./src/mandelbar.c\
			./src/action.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(SRC) $(LIB) $(MLX) -lmlx -framework OpenGL -framework OpenCL -framework AppKit -o $@

$(LIB):
	@make -C libft

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -I $(INCL) -o$@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all