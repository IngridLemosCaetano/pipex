# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:29:52 by ilemos-c          #+#    #+#              #
#    Updated: 2025/10/21 13:49:02 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
INCLUDES = -I.
FLAGS = -Wall -Wextra -Werror $(INCLUDES)
AR = ar rcs

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c \
		ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c  ft_strncmp.c ft_strnstr.c \
		ft_atoi.c ft_itoa.c ft_strdup.c ft_substr.c ft_calloc.c \
		ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c

SRCS_PRINTF =	ft_printf/ft_printf_basic.c \
				ft_printf/ft_printf_pointer.c \
				ft_printf/ft_printf_unsigned_hex.c \
				ft_printf/ft_printf.c

SRCS_GNL =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	$(AR) $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@echo "✅ libft.a criada com sucesso!"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "✨ Bonus incluídos na libft.a!"

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF) $(OBJS_GNL)
	@echo "🧹 Objetos removidos!"

fclean: clean
	rm -f $(NAME)
	@echo "🗑️ libft.a removida!"

re: fclean all

.PHONY: all clean fclean re
