# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 13:36:34 by ingrid            #+#    #+#              #
#    Updated: 2025/10/23 14:42:00 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
INCLUDES = -I $(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c src/pipex.c src/pipex_utils.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ Executável pipex criado com sucesso!"

$(OBJS): src/pipex.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@find . -type f -name '*.o' -exec rm -f {} +
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Objetos removidos!"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️ pipex removido!"

re: fclean all

.PHONY: all clean fclean re
