# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 18:13:30 by haer-reh          #+#    #+#              #
#    Updated: 2025/11/15 18:23:36 by haer-reh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
		printf_utils.c
OBJ = $(FILES:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus