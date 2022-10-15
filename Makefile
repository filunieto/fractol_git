# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 22:26:19 by fnieves-          #+#    #+#              #
#    Updated: 2022/10/15 17:57:44 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= 		fractol

CC 		= 		cc

FLAGS		= 		-Wall -Wextra -Werror -g

SRC 		= 	main.c								\
				src/parsing.c						\
				src/inicialize.c					\
				src/print_fractal.c					\
				src/error_handling.c				\
				src/mandelbrot.c					\
				src/julia.c							\
				src/color.c							\
				src/tools.c							\
				src/moves.c							\


OBJ 		= 		${SRC:.c=.o}

LIBS		= 		./libft/libft.a 						\


$(NAME): $(OBJ)
	make -C ./minilibx
	make -C ./libft
	${CC} ${FLAGS} ${OBJ} -o fractol  ${LIBS}  -L./minilibx -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

clean:
	cd minilibx && make clean
	cd libft && make clean
	rm -f ${OBJ}

fclean: clean
	cd libft && make fclean
	rm -f ${OBJ}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
