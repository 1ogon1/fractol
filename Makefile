#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:25:28 by mkyianyt          #+#    #+#              #
#    Updated: 2017/03/24 15:18:41 by rkonoval         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fractol

SRC = fractol.c\
	  burning_ship.c\
	  ft_create_fract.c\
	  ft_replaceimg.c\
	  ft_error.c\
	  ft_menu.c\
	  julia.c\
	  key_init.c\
	  mandelbrot.c\
	  mouse_init.c\
	  newton.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

ATTACH = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\x1b[35mCompile libft.\x1b[0m"
	@make -C libft
	@echo "\x1b[32mOK\x1b[0m"
	@echo "\x1b[35mCompile fractol.\x1b[0m"
	@gcc $(CFLAGS) -o $(NAME) -L libft -lft $(OBJ) $(ATTACH)
	@echo "\x1b[32mOK\x1b[0m"

.c.o:
	@gcc $(CFLAGS) -c $< -o $@ \

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "\x1b[32mClean OK\x1b[0m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\x1b[32mFClean OK\x1b[0m"

re: fclean all
