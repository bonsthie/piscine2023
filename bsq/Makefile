# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 13:05:57 by psalame           #+#    #+#              #
#    Updated: 2023/08/02 16:24:50 by babonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/get_greater_square.c srcs/generate_square.c srcs/ft_string.c srcs/ft_map.c srcs/file_manager.c srcs/main.c srcs/input_reader.c srcs/ft_atoi.c srcs/check_char.c
OBJS = ${SRCS:.c=.o}
HSRCS = ./includes
NAME = bsq

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} $^ -I ${HSRCS} -o $@ -c

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re