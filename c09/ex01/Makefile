NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs/
INC_DIR = includes/
SRC = $(SRC_DIR)ft_putchar.c $(SRC_DIR)ft_swap.c $(SRC_DIR)ft_putstr.c $(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strcmp.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
