# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 15:47:55 by gda-cruz          #+#    #+#              #
#    Updated: 2022/12/19 15:47:47 by gda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors #
GREEN		=	\033[1;32m
LIGHT_GREEN	=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

NAME = pipex

LIBFT_DIR	=	libft
SRC		=	srcs/mandatory/main.c \
			srcs/mandatory/setup.c \
			srcs/mandatory/command_setup.c \
			srcs/mandatory/free.c \
			srcs/mandatory/utils.c

B_SRC		=	srcs/bonus/main_bonus.c \
			srcs/bonus/setup_bonus.c \
			srcs/bonus/command_setup_bonus.c \
			srcs/bonus/free_bonus.c \
			srcs/bonus/utils_bonus.c

OBJ			=	$(SRC:srcs/mandatory/%.c=$(OBJ_DIR)/%.o)
B_OBJ		=	$(B_SRC:srcs/bonus/%.c=$(B_OBJ_DIR)/%.o)
INC_DIR		=	inc
BUILD_DIR	=	./build
BIN_DIR		=	$(BUILD_DIR)/bin
OBJ_DIR		=	$(BUILD_DIR)/objects
B_OBJ_DIR	=	$(BUILD_DIR)/b_objects
BIN			=	$(BIN_DIR)/$(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(BIN)

$(BIN):	$(OBJ) | $(BIN_DIR)
	@echo ""
	@echo "$(YELLOW)  Preparing Pipex...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(LIGHT_GREEN)  Libft successfully compiled.$(RESET)"
	@$(CC) $(CFLAGS) -o $(@) $(^) -L$(LIBFT_DIR) -lft
	@echo "$(LIGHT_GREEN)  Pipex successfully compiled.$(RESET)"
	@echo "$(GREEN) $(RESET)"
	@echo "$(GREEN) _______   _____   _______    _______   ___   ___  $(RESET)"
	@echo "$(GREEN) |||||||\ |||||||  |||||||\  ||||||||| ||||| ||||| $(RESET)"
	@echo "$(GREEN)  |||__)|   |||     |||__)|   |||_ \||   \\\\\   //   $(RESET)"
	@echo "$(GREEN)  ||||||/   |||     ||||||/   ||||| _     >> <<     $(RESET)"
	@echo "$(GREEN) _|||_     _|||_   _|||_     _|||__/||  _//_ _\\\\\_  $(RESET)"
	@echo "$(GREEN) ||||||   |||||||  ||||||    ||||||||| ||||| ||||| $(RESET)"
	@echo "$(GREEN)\n$(RESET)"

$(OBJ_DIR)/%.o:	srcs/mandatory/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $(^) -o $(@)

.SILENT = $(OBJ)
.SILENT = $(B_OBJ)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(B_OBJ_DIR) $(BIN_DIR)

bonus: $(B_OBJ) | $(BIN_DIR)
	@echo ""
	@echo "$(YELLOW)  Preparing Pipex...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(LIGHT_GREEN)  Libft successfully compiled.$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(^) -L$(LIBFT_DIR) -lft
	@echo "$(LIGHT_GREEN)  Pipex successfully compiled.\n$(RESET)"
	@mv pipex build/bin

$(B_OBJ_DIR)/%.o:	srcs/bonus/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $(^) -o $(@)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(B_OBJ_DIR)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -rf build
	@echo "$(RED)All Pipex files removed.$(RESET)"

re: fclean all

mandatory_path: all
	@./build/bin/pipex input.txt "/bin/grep give" "wc -l" output.txt

mandatory_normal: all
	@./build/bin/pipex input.txt "grep give" "wc -l" output.txt

bonus_mc1: bonus
	@./build/bin/pipex input.txt "grep give" "grep you" "wc -l" output.txt

bonus_mc2: bonus
	@./build/bin/pipex input.txt "ls -l" "grep .txt" "grep input" "wc -l" output.txt

bonus_hd: bonus
	@./build/bin/pipex here_doc EOF "grep azul" "grep bicicleta" "wc -l" output.txt

.PHONY: all clean fclean re bonus