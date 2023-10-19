# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2023/10/19 13:28:04 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = fdf

SRC_DIR = src

OBJ_DIR = src

LIBFT_NAME = libft.a

LIBFT_DIR = libft

LIB1_NAME = libmlx.a

LIB1_DIR = ~/Downloads/minilibx_macos

INCLUDE_DIR = include

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(LIB1_DIR) -L $(LIB1_DIR) -lmlx -framework OpenGL -framework AppKit -fsanitize=address

SRC_FILES = fdf_utils.c \
			fdf_utils_1.c \
			fdf_utils_2.c \
			fdf_utils_3.c

MAIN_DIR = .

MAIN_FILE = fdf.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# ************************************RULES*********************************** #

$(BIN_NAME): $(LIB1_NAME) $(LIBFT_NAME) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) -o $(BIN_NAME)

$(LIBFT_NAME):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)
	cp $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) .

$(LIB1_NAME):
	make $(LIB1_NAME) -C $(LIB1_DIR)
	cp $(addprefix $(LIB1_DIR)/,$(LIB1_NAME)) .

all: $(BIN_NAME)

clean:
	rm -f $(LIBFT_NAME) $(LIB1_NAME)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIB1_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
