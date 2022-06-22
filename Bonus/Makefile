# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 15:38:17 by obraiki           #+#    #+#              #
#    Updated: 2022/03/19 17:53:50 by obraiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

SOURCE = check_map.c ft_putnbr.c ft_split.c libft.c move.c move_enemy.c put_map.c read_map.c so_long_bonus.c

DEFS = so_long_bonus.h

MLX = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

bonus : $(NAME)

$(NAME) : so_long_bonus.c $(DEFS) $(OBJ)
	@$(CC) $(CFLAGS) $(SOURCE)  $(MLX) -o $(NAME)

clean:
	@rm *.o

fclean: clean
	@rm $(NAME)

re: fclean all