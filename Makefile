SRCS = main.c
OBJES = ${SRCS:.c=.o}

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LML = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJES)
	$(CC) ${CFLAGS} ${LML} $(SRCS) -o $(NAME) && ./${NAME}
	

all : ${NAME}

clean:
		${RM} *.o ${NAME}

re:	clean all

.PHONY: all clean fclean re 