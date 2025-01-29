# Source files
SRCS =	main.c \
		str_utils.c \
		init.c \
		math_utils.c \
		render.c \
		events.c

# Object files
OBJS = ${SRCS:.c=.o}

# Target binary name
NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f

# Configuración de MiniLibX
MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INCLUDE = -I$(MLX_DIR)
MLX_FLAGS = -lX11 -lXext -lm

HEADER = fractol.h

# Build everything
all: $(NAME)

# Compile .c to .o
%.o: %.c
	${CC} ${CFLAGS} $(MLX_INCLUDE) -c $< -o $@

# Build the program
$(NAME): $(OBJS) Makefile $(HEADER)
	${CC} ${CFLAGS} $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o ${NAME}

# Clean objects
clean:
	${RM} ${OBJS}

# Clean all files
fclean: clean
	${RM} ${NAME}

# Rebuild project
re: fclean all

.PHONY: all clean fclean re
