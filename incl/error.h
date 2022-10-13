/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:30 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/13 12:41:41 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define USAGE "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
\tspecify at least one parameter:\n\
\t fractal name: <Mandelbrot/Julia/.../M/J/.>\n\n\
\tthe following optional parameters may be used:\n\
\t  color: <bernstein/rainbow/psychedelic/be/ra/ps/b/r/p>\n\
\t  for Julia only: <real axis coordinate> <imaginary axis coordinate>\n"

# define USAGE1 "\n\tUsage 1\n\n\
\t usage1\n"

# define ERROR_MANDELBROT "\tUsage for Mandelbrot ./fractol <Mandelbrot/M/1/>\n\
\tNo need of more paremeters \n"

# define ERROR_INIZIALICE "\tError with instance mlx\n"
# define ERROR_INIZIALICE_WIN "\tError with window win\n"

// # define LESS_ARGUMENTS "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
// \tToo few arguments!\n\
// \tplease you need to introduce\n\
// \tmore arguments \n\n\"

// # define MANY_ARGUMENTS "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
// \tToo many arguments!\n\
// \tplease you need to introduce\n\
// \tless arguments \n\n\"

#endif