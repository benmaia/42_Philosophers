# COLORS #
BLACK			=	\e[1;30m
RED 			=	\e[1;31m
GREEN			=	\e[1;32m
YELLOW		=	\e[1;33m
BLUE			=	\e[1;34m
PURPLE		=	\e[1;35m
CYAN			=	\e[1;36m
WHITE			=	\e[1;37m
ORANGE1		=	\033[38;5;214m"
ORANGE2		=	\033[38;5;202m"
RES			=	\e[0m

# NAME OF THE PROGRAM #
NAME		=	philo

# DIRECTORIES #
INC_DIR		=	inc
BUILD_DIR	=	build
SRC_DIR		=	srcs
OBJ_DIR		=	$(BUILD_DIR)/objects

# FILES .C #
SRC		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/exec.c \
				$(SRC_DIR)/init.c \
				$(SRC_DIR)/parser.c \

# FILES .O #
OBJ			=	$(patsubst %.c, %.o, $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC)))

# COMPILER & FLAGS #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -static-libasan -g
LDFLAGS		= -fsanitize=address -static-libasan -g

# LIBRARIES #
INCLUDES	=	-I$(INC_DIR)

# SILENCE THE COMPILER #
.SILENT		=	$(OBJ)

all: $(BUILD_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(^) -o $(@)
	@echo "$(GREEN)[ Philosophers is ready to use! ] $(RESET)"
	@echo "$(PURPLE)[ Run ./philo with 4 or 5 arguments!] $(RESET)"
	@echo "$(BLUE)[ It need's at least 1 philosopher, and you can only ] $(RESET)"
	@echo "$(BLUE)[ pass positive numbers, no signs and no chars/strings ] $(RESET)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)
	@echo "$(GREEN)[ Creating $(notdir $@) ]$(RESET)"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(YELLOW)[ Objects have been removed! ]$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[ Philosophers has been removed! ]$(RESET)"

re: fclean all
