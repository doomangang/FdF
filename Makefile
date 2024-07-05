NAME		= fdf

SRCS 		= fdf.c source/parse.c source/draw.c source/window.c \
 funcLib/libft/ft_split.c funcLib/libft/ft_strjoin.c\
 funcLib/libft/ft_strlen.c funcLib/libft/ft_strdup.c funcLib/libft/ft_strlcpy.c\
 funcLib/libft/ft_memcpy.c funcLib/libft/ft_atoi.c funcLib/libft/ft_strncmp.c\
 funcLib/libft/ft_isdigit.c

OBJS 		= $(SRCS:.c=.o)

HEADER		= $(HEADER_DIR)fdf.h
HEADER_DIR	= header/

MINILIBX_DIR= minilibx_mms_20191025_beta/
MINILIBX_DYLIB = $(MINILIBX_DIR)libmlx.dylib

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
GL_LINK		= -lmlx -lm -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES	= -I$(HEADER_DIR) -I$(MINILIBX_DIR)

RM			= rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(MINILIBX_DYLIB) $(OBJS)
	cp $(MINILIBX_DYLIB) .
	$(CC) $(CFLAGS) $(GL_LINK) $(INCLUDES) $(OBJS) -o $(NAME)

$(MINILIBX_DYLIB):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(MAKE) -sC $(MINILIBX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) libmlx.dylib
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re