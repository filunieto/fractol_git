/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:30 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 12:53:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define USAGE "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
\tspecify at least one parameter:\n\
\tfractal name: <Mandelbrot/Julia/.../M/J/1>\n\n\
\tfractal name could be whole name (Julia) or \n\
\tfirst letter: M, J, B, C,...or a number between 1 and 4\n\n\
\tfor Julia only: <real axis coordinate> <imaginary axis coordinate>\n"

# define ERROR_MANDELBROT "\tUsage for Mandelbrot/Colibri/Burning ship\n\
\t./fractol <Mandelbrot/M/1/> or\n\
\t./fractol <Burning/b/3/> or\n\
\t./fractol <colibri/c/4/>\n\
\tNo need of more than 1 paremeters with the name \n"

# define ERROR_JULIA "\n\tJulia usage:\n\n\
\t ./fractol Julia <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia\n\n\
\tNB provide either zero or two valid coordinates for Julia set\n\
\tCoordinates should be representable as a double, in range [-2, 2] e.g.:\n\n\
\t\t./fractol Julia 0.1534 -2.17\n\n\
\tIf no coordinates are provided, default coordinates {-0.79, -0.09} will\
 be used\n"

# define ERROR_INIZIALICE "\tError with instance mlx\n"
# define ERROR_INIZIALICE_WIN "\tError with window win\n"

#endif