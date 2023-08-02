FLAG = -Wall -Wextra -Werror
CC = gcc
NAME = rush-02
SRC = main.c print.c parsing.c lib.c
OBJ = $(SRC:.c=.o) 
.PHONY : all clean fclean

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(FLAG) # $@ fait referance au noms de la fonction donc $(NAME)

%.o : %.c 
	$(CC) -o $@ -c $< $(FLAG)

clean : 
	rm -rf *.o

fclean : clean 
	rm -rf $(NAME)