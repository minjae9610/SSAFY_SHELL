NAME			=	ssafy

PRE				=	srcs/
SRCS			=	ssafy_shell.c

CFILES			=	${addprefix ${PRE}, ${SRCS}}
OBJS			=	${CFILES:.c=.o}

INC				=	includes

LIBSSAFYSHELL	=	ssafy_shell_lib

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

LIBC			=	ar rcs

REMOVE			=	rm -f

all:				${NAME}

%.o : %.c
					${CC} ${CFLAGS} -c $< -o $@ -I ${LIBSSAFYSHELL} -I ${INC}

${NAME}:			${OBJS}
					@${MAKE} -C ${LIBSSAFYSHELL}
					${CC} ${OBJS} -o ${NAME} -L ${LIBSSAFYSHELL} -lssafyshell

clean:
					${REMOVE} ${OBJS}
					@${MAKE} -C ${LIBSSAFYSHELL} clean

fclean:
					@${MAKE} clean
					${REMOVE} ${NAME}
					@${MAKE} -C ${LIBSSAFYSHELL} fclean

re:
					@${MAKE} fclean
					@${MAKE}

.PHONY:				all clean fclean re