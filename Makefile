NAME1	= server
NAME2	= client
NAME1_BONUS	= server_bonus
NAME2_BONUS	= client_bonus

SRCS 	= client.c server.c
SRCS_B	= ./bonus/client_bonus.c ./bonus/server_bonus.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
CC 		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME1) $(NAME2)

bonus: $(NAME1_BONUS) $(NAME2_BONUS)

$(NAME1) : ${OBJS}
	$(CC) $(CFLAGS) server.o -o $(NAME1)

$(NAME2) : $(OBJS)
	$(CC) $(CFLAGS) client.o -o $(NAME2)

$(NAME1_BONUS) : ${OBJS_B}
	$(CC) $(CFLAGS) ./bonus/server_bonus.o -o $(NAME1_BONUS)

$(NAME2_BONUS) : $(OBJS_B)
	$(CC) $(CFLAGS) ./bonus/client_bonus.o -o $(NAME2_BONUS)

clean :
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME1} ${NAME2} ${NAME1_BONUS} ${NAME2_BONUS}

re : fclean all

.PHONY: all clean fclean re bonus
