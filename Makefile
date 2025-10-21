# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 13:36:34 by ingrid            #+#    #+#              #
#    Updated: 2025/10/21 13:48:57 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "✅ pipex.a criada com sucesso!"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "🧹 Objetos removidos!"

fclean: clean
	rm -f $(NAME)
	@echo "🗑️ pipex.a removida!"

re: fclean all

.PHONY: all clean fclean re
