SRCS	= ft_display_file.c ft_putstr.c main.c
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CCFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAME	= ft_display_file

.c.o:
			${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
