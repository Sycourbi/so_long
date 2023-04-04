# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:59:27 by sycourbi          #+#    #+#              #
#    Updated: 2023/02/02 13:07:04 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/main.c \
	./src/check_map.c \
	./src/create_map.c \
	./src/error.c \
	./src/init.c \
	./src/graphic.c \
	./src/graphic2.c \
	./src/move.c \
	./src/flip_flop.c \
	
OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

CC = gcc

CFLAG = -Wall -Wextra -Werror -g3
MFLAG = -lX11 -lXext -lm

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAG) $< -o $@ -I.
# -c sert a creer fichier objet
# -o sert a creer le fichier executable
# -I. sert a inclure les header (.h)

$(NAME): $(MLX) $(OBJ)
	make -C ./libft
# -C pour rajouter la direction (faire make dans le dossier libft)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB) -I. $(MLX) $(MFLAG) -I.

$(MLX) : 
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
	make -C ./minilibx-linux
clean:
	rm -rf minilibx-linux
	cd libft && make clean
	rm -rf $(OBJ)
# -r sert a effacer recursivement les sous repertoires
# -f sert a ne pas demander de confirmation d'effacement, et ne pas renvoyer de code erreur quand le fichier n'existe pas

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
