NAME = libft.a

CC = gcc -Wall -Werror -Wextra

SRC_DIR = ./srcs
OBJ_DIR = ./obj
SRC := $(shell find $(SRC_DIR) -name "*.c" -execdir basename {} \;)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
INCLUDE = -Iincludes

all: $(NAME)
	@echo "${GREEN}libft.a compile successful!${NC}"

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "libft.a not available, compiling now..."
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

so:
	$(CC) -nostartfiles -fPIC $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so *.o

test: $(NAME) bonus
	@$(CC) test.c -L. -lft && ./a.out

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m # No Color