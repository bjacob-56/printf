SRCS	=   *.c

OBJS = ${SRCS:.c=.o}

#${OBJS}:    ${SRCS}
#	       ${CC} ${CFLAGS} ${SRCS}

NAME = libftprintf.a
CC ?= gcc
AR ?= ar
RM ?= rm -f
CFLAGS = -Wall -Wextra -Werror -I.

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME):	${OBJS}
	${AR} rcs ${NAME} ${OBJS}

# A SUPPRIMER
so:
		gcc -fPIC -c *.c
		gcc -shared -Wl,-soname,libftprintf.so -o libftprintf.so *.o

all : 		${NAME}

clean :
	${RM} ${OBJS}

fclean : 	clean
	${RM} ${NAME}

re :		fclean all

.PHONY: all clean fclean re libftprintf.a
