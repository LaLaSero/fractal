NAME = fractol
SRCS = srcs/main.c srcs/check_args.c srcs/render_fractol.c srcs/colorlify.c srcs/fractol_funcs.c
SRCS += srcs/handle_key_event.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
LIBX_FLAGS = -lmlx_Linux -lXext -lX11 -g -fsanitize=leak -lm

all:		libft $(NAME)

libft:
			$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re libft
