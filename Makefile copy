NAME := philo

LIB_DIR := libft
EXE_DIR := execution
UTILS_DIR := utils
INIT_DIR := init
ERRORS_DIR := errors
OBJ_DIR := objs
OBJ_DIR_COLLECTION := $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(EXE_DIR) \
					  $(UTILS_DIR) $(INIT_DIR) $(ERRORS_DIR)) \

SOURCE := philo.c \
		  $(addprefix $(EXE_DIR)/, \
		  process.c) \
		  $(addprefix $(INIT_DIR)/, \
		  init.c) \
		  $(addprefix $(ERRORS_DIR)/, \
		  errors.c) \
		  
OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

HEADER := include/philo.h

LIBFT := $(LIB_DIR)/libft.a

RM := rm
CC := cc
MAKE_DIR := mkdir
MAKE := make

RM_FLAG := -rf
CC_FLAG := -Wall -Werror -Wextra
MAKE_FLAG := -C

all: $(LIBFT) $(NAME)

$(LIBFT):
	@if [ -z "$(shell ls -A $(LIB_DIR))" ]; then \
		git submodule init $(LIB_DIR); \
		git submodule update $(LIB_DIR); \
	fi
	@echo "$(BLUE)Started compiling libft...$(NC)"
	@$(MAKE) $(MAKE_FLAG) $(LIB_DIR)
	@echo "$(GREEN)Builded libft successfully$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER)
	@$(CC) $(CC_FLAG) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIB_DIR)/objs
	@echo "$(GREEN)Clean successfull$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT)
	@echo "$(GREEN)Full clean successfull$(NC)"

re: fclean all

clean_lib:
	@cd $(LIB_DIR) && ls -A | xargs rm -rf
	@echo "$(GREEN)Library clean successfull$(NC)"

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	@echo "$(BLUE)Compiling...$(NC)"
	$(MAKE_DIR) $(OBJ_DIR_COLLECTION)

.PHONY: all clean fclean re clean_lib

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m