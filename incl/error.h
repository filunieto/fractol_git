/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:30 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/09 20:21:38 by fnieves-         ###   ########.fr       */
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

// # define LESS_ARGUMENTS "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
// \tToo few arguments!\n\
// \tplease you need to introduce\n\
// \tmore arguments \n\n\"

// # define MANY_ARGUMENTS "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
// \tToo many arguments!\n\
// \tplease you need to introduce\n\
// \tless arguments \n\n\"

#endif