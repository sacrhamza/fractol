CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = fractol

FILES = mandatory/fractol.c mandatory/mouse_events.c mandatory/key_events.c mandatory/close_window.c mandatory/fractol_utils.c mandatory/display_help.c mandatory/libft_func.c

OBJECT_FILES = $(FILES:%.c=%.o)

HEADER_FILE = fractal.h

all: $(NAME)

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJECT_FILES) mandatory/ft_printf/libftprintf.a
	$(CC) $(FLAGS) $(OBJECT_FILES) -O3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@ -Lmandatory/ft_printf -lftprintf

mandatory/ft_printf/libftprintf.a:
	make -C mandatory/ft_printf

clean:
	make -C mandatory/ft_printf clean
	$(RM) $(OBJECT_FILES) 

fclean: clean
	make -C mandatory/ft_printf fclean
	$(RM) $(NAME)

re: fclean all

DATE = $(shell date +%F/%H/%M)

push:
	push "fractol automatic push $(DATE)"

norm:
	norminette $(FILES) $(HEADER_FILE)
