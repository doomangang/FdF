NAME			= fdf

SRCS 			= fdf.c\
				source/parse.c\
				source/draw.c\
				source/projection.c\
				source/window.c

OBJS 			= $(SRCS:.c=.o)

HEADER			= $(HEADER_DIR)fdf.h
HEADER_DIR		= header/

MINILIBX_DIR	= minilibx_mms_20191025_beta/
MINILIBX_DYLIB	= $(MINILIBX_DIR)libmlx.dylib

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= funcLib/libft/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
GL_LINK			= -lmlx -lm -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
FT_LINK			= -lft -L$(LIBFT_DIR)
INCLUDES		= -I$(HEADER_DIR) -I$(MINILIBX_DIR) -I$(LIBFT_DIR)

RM				= rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(MINILIBX_DYLIB) $(OBJS)
	@cp $(MINILIBX_DYLIB) .
	@$(CC) $(CFLAGS) $(FT_LINK) $(GL_LINK) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME): object file and $(NAME) created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(NAME): $(LIBFT) created"

$(MINILIBX_DYLIB):
	@$(MAKE) -sC $(MINILIBX_DIR)
	@echo "$(NAME): $(MINILIBX_DYLIB) created"
clean:
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "$(NAME): objects deleted"

fclean: clean
	@$(RM) libmlx.dylib
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(NAME): $(NAME), $(MINILIBX_DYLIB), $(LIBFT) deleted"

re: fclean all

.PHONY : all clean fclean re