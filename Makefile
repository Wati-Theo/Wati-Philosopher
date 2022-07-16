NAME = philo

SRCS = ./Wati-Srcs/Wati-Main.c ./Wati-Srcs/Wati-Parsing.c ./Wati-Srcs/Wati-Utilis.c

OBJS = ${SRCS:.c=.o}

INC = ./Wati-Includes/Wati_Philosopher.h

CC  = gcc

RM  = rm -f

CFLAGS = -Wall -Wextra -Werror -I ./includes -g

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(INC)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re