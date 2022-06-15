NAME	= count_island

CC	= gcc

C_FLAGS	= -Wall -Werror -Wextra

SRCS	= count_island.c functions.c functions2.c spread.c

HEADER	= header.h

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

.c.o:
		${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${CC} ${C_FLAGS} -I ${HEADER} ${OBJS} -o ${NAME}

clean:
		rm -rf *.o

fclean:	clean
		rm -rf ${NAME}

re:	fclean all
