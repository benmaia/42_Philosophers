# Colors #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET		=	\033[0m

NAME		=	philo

INC_DIR		=	inc
BUILD_DIR	=	build
SRC_DIR		=	srcs
OBJ_DIR		=	$(BUILD_DIR)/objects

SRC		=	$(SRC_DIR)/main.c \

OBJ			=	$(patsubst %.c, %.o, $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC)))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -static-libasan -g
LDFLAGS		= -fsanitize=address -static-libasan -g
INCLUDES	=	-I$(INC_DIR)

.SILENT		=	$(OBJ)

all: $(BUILD_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(^) -o $(@) $(LINKS)
	@echo "$(GREEN)[ Philosophers is ready to use! ] $(RESET)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "$(GREEN)[ Creating $(notdir $@) ]$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(YELLOW)[ Objects have been removed! ]$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[ Minishell has been removed! ]$(RESET)"

re: fclean all
