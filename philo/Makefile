NAME := philo

OBJ_DIR := objs

SOURCE := philo.c \
          eating.c \
          errors.c \
          process.c \
          init.c \
          sleeping.c \
          thinking.c \
          time.c \
          utils.c

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

HEADER := philo.h

RM := rm
CC := cc
MAKE_DIR := mkdir
MAKE := make

RM_FLAG := -rf
CC_FLAG := -Wall -Werror -Wextra
MAKE_FLAG := -C

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CC_FLAG) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build successful$(NC)"

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR)
	@echo "$(GREEN)Clean successful$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME)
	@echo "$(GREEN)Full clean successful$(NC)"

re: fclean all

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Compiling...$(NC)"
	@$(MAKE_DIR) -p $(OBJ_DIR)

.PHONY: all clean fclean re

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m
