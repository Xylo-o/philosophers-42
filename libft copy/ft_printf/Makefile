NAME = libftprintf.a
INCLFAG = -I.
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ft_printf.c \
	cases_nums.c \
	cases_hex.c \
	cases_other.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all