NAME			= fdf

SRCS 			= fdf.c\
				source/parse.c\
				source/draw.c\
				source/projection.c\
				source/window.c
SRCS_B			= fdf_bonus.c\
				bonus/parse.c\
				bonus/draw.c\
				bonus/projection.c\
				bonus/window.c

OBJS 			= $(SRCS:.c=.o)
OBJS_B			= ${SRCS_B:.c=.o}

HEADER			= $(HEADER_DIR)fdf.h
HEADER_B		= $(HEADER_DIR)fdf_bonus.h
HEADER_DIR		= header/

MINILIBX_DIR	= minilibx_mms_20191025_beta/
MINILIBX_DYLIB	= $(MINILIBX_DIR)libmlx.dylib

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= funcLib/libft/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=undefined
GL_LINK			= -lmlx -lm -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
FT_LINK			= -lft -L$(LIBFT_DIR)
INCLUDES		= -I$(HEADER_DIR) -I$(MINILIBX_DIR) -I$(LIBFT_DIR)

RM				= rm -f

ifdef WITH_BONUS
	OBJ_SWITCH	= ${OBJS_B}
	H_SWITCH	= $(HEADER_B)
	NAME		= fdf_bonus
else
	OBJ_SWITCH = ${OBJS}
	H_SWITCH	= $(HEADER)
endif

all: $(NAME)

bonus:
	${MAKE} WITH_BONUS=1 all

%.o: %.c $(H_SWITCH)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(MINILIBX_DYLIB) $(OBJ_SWITCH)
	@cp $(MINILIBX_DYLIB) .
	@$(CC) $(CFLAGS) $(FT_LINK) $(GL_LINK) $(INCLUDES) $(OBJ_SWITCH) -o $(NAME)
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
	@$(RM) $(OBJS) $(OBJS_B)
	@echo "$(NAME): objects deleted"

fclean: clean
	@$(RM) libmlx.dylib
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(NAME): $(NAME), $(MINILIBX_DYLIB), $(LIBFT) deleted"

re: fclean all

.PHONY : all clean fclean re bonus