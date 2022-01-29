NAME = push_swap

CC = gcc -Wall -Wextra -Werror -fsanitize=address -g3

SRC_DIR = ./src
OBJ_DIR = ./obj
SRC := $(shell find $(SRC_DIR) -name "*.c" -execdir basename {} \;)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE = -I. -Ilibft

LIBFT = libft/libft.a
LIB_FLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	@echo "${GREEN}Compile successful!${NC}"

$(LIBFT): libft/libft.h
	@make bonus -C libft

libft/libft.h:
	@git submodule init
	@git submodule update

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "${RED}Removed all object files...${NC}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${RED}Removed $(NAME)...${NC}"

re: fclean all

.PHONY: clean fclean re all

# Colors are great!
# Formats are greater!
# https://misc.flogisoft.com/bash/tip_colors_and_formatting
RED = \033[31m
GREEN = \033[32m
NC = \033[0m # No Color