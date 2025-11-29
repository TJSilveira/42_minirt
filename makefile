#Colors
GREEN		=	\033[1;32m
LIGHT_GREEN	=	\033[0;32m
RED			=	\033[1;31m
YELLOW		=	\033[0;33m
ITALIC		=	\033[3m
RESET		=	\033[0m

NAME = minirt

CC = cc

CFLAGS = -Wall -Werror -Wextra

# Includes
INCLUDES = -I ./includes/

# Directories
SRC_DIR 	= ./src/
OBJS_DIR 	= ./objs/
LIBFT_DIR 	= ./libft/
MLX_DIR		= ./minilibx-linux/
BIN_DIR		= ./bin/

# Source Files
SRC         =   $(shell find src/ -name '*.c')

# Object Files
OBJS        =   $(patsubst src/%.c,objs/%.o,$(SRC))

# Binary File
BIN			= $(addprefix $(BIN_DIR), $(NAME))

# Libraries
# LIBFT = $(LIBFT_DIR)libft.a
LIBRARIES = -lft -lreadline

all: ${NAME}

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

# creating executables
${NAME}: ${OBJS_DIR} ${BIN_DIR} ${OBJS}
	@echo ""
	@echo "$(YELLOW) Compiling libft... $(RESET)"
	make bonus -C ${LIBFT_DIR}
	@echo "$(YELLOW) libft Compiled... $(RESET)"
	@echo "$(YELLOW) Compiling mlx... $(RESET)"
	make -C ${MLX_DIR}
	@echo "$(YELLOW) mlx Compiled... $(RESET)"
	@echo "$(YELLOW) Preparing minirt... $(RESET)"
	@${CC} ${CFLAGS} ${OBJS} -L${MLX_DIR} -L${LIBFT_DIR} -lft -lmlx_Linux -lmlx -lXext -lX11 -lm -o ${BIN}
	@echo "$(LIGHT_GREEN) minirt successfully compiled.$(RESET)"

# Creating Object file folder
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Creating object files
$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

# Creating Binary file folder
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf ./libft/*.o

fclean: clean
	rm -rf ${NAME} out* valgrind*
	rm -rf ./libft/*.a
	rm -rf ${BIN_DIR}

re: fclean ${NAME}
	@clear

test: re
	@./minirt

rebonus: fclean bonus

valgrind:
	@valgrind --leak-check=full --track-fds=yes -s --show-leak-kinds=all --track-origins=yes ./bin/minirt test1.rt

.PHONY: all clean fclean re