COMMAND := cc -c -Wall -Werror -Wextra

#objects for the Mandatorydatory part
MANDATORY_FILES := fn_printf.c fn_global.c fn_putchar.c fn_itoa.c \
	   fn_putstr.c fn_putptr.c fn_puthex.c fn_puthexptr.c \
	   fn_putnbr.c fn_putus.c fn_tolower.c fn_toupper.c


OBJECTS = ${MANDATORY_FILES:.c=.o}

NAME = libftprintf.a

all: ${NAME}

HEADER = fn_printf_bonus.h

${NAME}: ${OBJECTS}
	ar rcs $@ $^

%.o: %.c
	${COMMAND} $< -o $@

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONEY: clean
