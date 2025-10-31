# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 13:36:34 by ingrid            #+#    #+#              #
#    Updated: 2025/10/31 16:10:50 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
INCLUDES = -I $(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c src/pipex.c src/pipex_utils.c
SRCS_BONUS = src/main_bonus.c src/pipex_bonus.c src/pipex_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ Executável pipex criado com sucesso!"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
	@echo "🌟 Executável $(NAME_BONUS) (versão BONUS) criado com sucesso!"

$(OBJS): src/pipex.h
$(OBJS_BONUS): src/pipex_bonus.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@find . -type f -name '*.o' -exec rm -f {} +
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Objetos removidos!"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️ Executáveis pipex e pipex_bonus removidos!"

re: fclean all

.PHONY: all clean fclean re
