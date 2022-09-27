/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:17:59 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 21:45:48 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h> //quitarla
#include <unistd.h>
#include <string.h>
#include <memory.h>
# include <math.h>
# include "structures.h"
# include "keys.h"
# include "error.h"


#define MAX_ITERATIONS 40 // Maximum number of iterations
#define WIDTH 800	// Width of the window (in pixels)
#define HEIGHT 800	// Height of the window (in pixels)
#define WIDTH_PIXEL 20
#define HEIGHT_PIXEL 40
#define BPP sizeof(int32_t)


/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2


/*  Parsing functions	*/
void	parse_argum(t_mlxwin  *guide, int argc, char **argv);

/*  Inicialize functions	*/
void	null_inicialize(t_mlxwin *guide);
void	fractol_inicialize(t_mlxwin *guide);

/*  Error & exit functions	*/
void	error_exit(char *message, t_mlxwin *guide, int exit_code);
void	clean_exit(int exit_code, t_mlxwin  *guide);

int	check_keys(int keycode, t_mlxwin  *guide);
void	close_window(t_mlxwin  *guide);


/*  Print fractals functions generic	*/
void	start_printing(t_mlxwin  *guide);
void	print_fractal1(t_mlxwin *guide);
int	fractal_function(t_mlxwin *guide, int x, int y);

t_complex	scaling_value(int x, int y, t_view_value *val);
void	my_mlx_pixel_put(t_mlxwin *guide, int x, int y, int color);


/*  Print fractals functions Mandelbrot	*/
int	mandelbrot(t_mlxwin *guide, int x, int y);

/*  Print fractals functions Julia	*/
int		 julia(t_mlxwin *guide, int x, int y);

/*  Colors	*/
int	color(int iteration);




#endif