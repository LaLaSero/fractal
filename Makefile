NAME        =   minilibx_test
SRCS        =   main.c check_args.c render_fractol.c
OBJS        =   $(SRCS:.c=.o)
LIBFT       =   ./libft/libft.a
LIBFT_DIR   =   ./libft
# Compiler
CC          =   cc
LIBX_FLAGS  =   -lmlx_Linux -lXext -lX11

# Rules
all:        libft $(NAME)

libft:
			$(MAKE) -C $(LIBFT_DIR)

$(NAME):    $(OBJS)
			$(CC) $(OBJS) $(LIBFT) $(LIBX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:     clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:         fclean all

.PHONY:     all clean fclean re libft
