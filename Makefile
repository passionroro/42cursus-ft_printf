SRCS		=	ft_printf.c	printfutils1.c	printfutils2.c

OBJS        = ${SRCS:.c=.o}

NAME        = libftprintf.a

CC            = gcc

CFLAGS        = -Wall -Wextra -Werror

AR_RCS        = ar rcs

all:            ${NAME}

.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
				@${AR_RCS} ${NAME} ${OBJS}

clean:
				@rm -f ${OBJS} 

fclean:			clean
				@rm -f ${NAME}

re:                fclean all

.PHONY:            all clean fclean re
