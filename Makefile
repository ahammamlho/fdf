SRC_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c 
SRCS = main.c valide.c fill_data.c utiles/utile1.c pixel_put.c
OBJES = ${SRCS:.c=.o}
OBJES_GNL = ${SRC_GNL:.c=.o}

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LML = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
FT_PRINTF = ./ft_printf

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all :  ${FT_PRINTF} ${NAME}

# ${NAME} : 
# 		$(CC) ${CFLAGS} ${SRCS} ${SRC_GNL} ${FT_PRINTF}/*.a -o ${NAME}

$(NAME): $(OBJES) $(OBJES_GNL)
	$(CC) $(OBJES) $(OBJES_GNL) ${FT_PRINTF}/*.a ${LML} -o $(NAME)

${FT_PRINTF} :
	${MAKE} -C ${FT_PRINTF}

clean:
		${RM} *.o
		${RM} ${NAME}
		${MAKE} clean -C ${FT_PRINTF}

re:	clean all

.PHONY: all clean fclean re ${FT_PRINTF}