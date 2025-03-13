CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = fractol

FILES = fractol.c #fractol_utils.c

OBJECT_FILES = $(FILES:%.c=%.o)

HEADER_FILE = fractal.h

all: $(NAME)

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJECT_FILES)
	$(CC) $(FLAGS) $(OBJECT_FILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
	$(RM) $(OBJECT_FILES) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

DATE = $(shell date +%F/%H/%M)

push:
	push "fractol automatic push $(DATE)"

norm:
	norminette $(FILES) $(HEADER_FILE)
