SRCSDIR	= ./srcs/
INCLDIR	= ./includes/
SRCS	= ${SRCSDIR}ft_putchar.c ${SRCSDIR}ft_swap.c ${SRCSDIR}ft_putstr.c ${SRCSDIR}ft_strlen.c ${SRCSDIR}ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
HEADER	= ${INCLDIR}ft.h

CC		= gcc
CCFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAMELIB	= libft.a

.c.o:
		${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

all:		${NAMELIB}

${NAMELIB}:	${OBJS}
			ar r ${NAMELIB} ${HEADER} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAMELIB}

re:			fclean all

.PHONY:		all clean fclean re ${NAMELIB}