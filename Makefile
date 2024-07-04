NAME	= fdf
SRCS 	= fdf.c source/parse.c funcLib/libft/ft_split.c funcLib/libft/ft_strjoin.c\
 funcLib/libft/ft_strlen.c funcLib/libft/ft_strdup.c funcLib/libft/ft_strlcpy.c\
 funcLib/libft/ft_memcpy.c

OBJS 	= ${SRCS:.c=.o}

HEADER	= fdf.h

CC				= cc
CFLAGS			= -Wall -Wextra
RM				= rm -f

all: ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re