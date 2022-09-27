# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 22:26:19 by fnieves-          #+#    #+#              #
#    Updated: 2022/09/27 21:30:45 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= 		fractol

CC 		= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 	main.c								\
				src/parsing.c						\
				src/inicialize.c					\
				src/print_fractal.c					\
				src/error_handling.c				\
				src/mandelbrot.c					\
				src/julia.c							\
				src/color.c							\


OBJ 		= 		${SRC:.c=.o}


LIBS		= 		./libft/libft.a 						\


$(NAME): $(OBJ)
	make -C ./minilibx
	make -C ./libft
	${CC} ${FLAGS} ${OBJ} -o fractol  ${LIBS}  -L./minilibx -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

# cd ./lib/ft_printf && make fclean && cd .. && cd .. Lo quite de abajo
clean:
	cd minilibx && make clean
	cd libft && make clean
	rm -f ${OBJ}

# cd .minilibx && make clean && cd .. 
fclean: clean
	cd libft && make fclean
	rm -f ${OBJ}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
