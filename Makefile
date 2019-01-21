#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:28:37 by akolinko          #+#    #+#              #
#    Updated: 2018/06/08 23:12:24 by akolinko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m
WAC = \x1b[33m

SRC = main.c ft_error.c check.c valid.c save_matrix.c new_window.c hook.c reycaster.c raycast.c values.c radar.c texture.c drav.c smog.c hook2.c fps.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ)  -lmlx\
    -framework OpenGl -framework AppKit -o $(NAME) -l ft -I libft -L libft

	@echo "$(OKC)wolf3d:\twolf3d ready$(NOC)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft
	@echo "$(WAC)wolf3d:\tObject was created$(NOC)"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "$(ERC)wolf3d:\tObjects were deleted$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(ERC)wolf3d:\twolf3d was deleted$(NOC)"

re: fclean all