# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 13:36:34 by ingrid            #+#    #+#              #
#    Updated: 2025/12/17 21:11:47 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/pipex.c $(SRC_DIR)/pipex_utils.c
SRCS_BONUS = $(SRC_DIR)/main_bonus.c $(SRC_DIR)/pipex_bonus.c $(SRC_DIR)/pipex_utils_bonus.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📁 Created obj directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/pipex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< → $@"

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "✅ Created $(NAME)"

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $@
	@echo "🌟 Created $(NAME_BONUS)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Removed object files and obj directory"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🗑️ Removed executables"

re: fclean all

.PHONY: all clean fclean re bonus
