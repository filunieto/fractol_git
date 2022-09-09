/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:43:18 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/09 20:06:56 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	mandelbrot(t_mlxwin *guide, int x, int y, double cr, double ci)
{
	int	n;	// Number of iterations 
	double	zr;	// Real part of Z
	double	zi;	// Imaginary part of Z
	double	tmp;	// Temporary variable
	// Variable to determine if a number is in the set or not:
	int	is_in_set; 

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		// As long as we're not at the maximum number of iterations,
		// we iterate
		//recuerda que el modulo del vector del numero inmaginario tiene que ser menor que 2 >>> sqrt(zr * zr + zi * zi) > 2
		if ((zr * zr + zi * zi) > 4.0)
		{
			// If the absolute value of Z exceeds 2
			// (zr * zr + zi * zi) > 4.0 == sqrt(zr * zr + zi * zi) > 2
			is_in_set = 0;
			// We flag that this number tends toward infinity, 
			// and is therefore not part of the set
			// and we stop iterating
			break ;
		}
		// Calculate the Mandelbrot formula for the next iteration.Revisrra esto en lateoria
		//Usa usa la variable tmp: para no perder el valor de la parte imaginaria 
		//Z = (Zr^2 - Zi^2 + Cr) || (2* Zr* Zi + C)i >>> de la formul Z = Z * Z + C
		tmp = 2 * zr * zi + ci; //(2* Zr* Zi + C)i
		zr = zr * zr - zi * zi + cr; //(Zr^2 - Zi^2 + Cr)
		zi = tmp;
	}
	// If the number is part of the Mandelbrot set,
	// set the pixel to black, otherwise to white
	if (is_in_set == 1)
		mlx_pixel_put(guide->mlx, guide->win, x, y, 0x000000); //negro dentro
	else if (is_in_set != 1)
	{
		if(n > 1 && n < 8 ) //si el numero de repetciones
			mlx_pixel_put(guide->mlx, guide->win, x, y, 0x00FF00);
		else
			mlx_pixel_put(guide->mlx, guide->win, x, y, 0xFFaaFF);//rosa en este caso
	}
}



void	print_mandelbrot(t_mlxwin *guide)
{
	// x and y coordinates of the pixel:
	int	x; // column
	int	y; // line
	t_fractol *f;
	
	f = guide->f;
	// to map the x and y coordinates of the pixel to a
	// complex number:
	double	pr; // real part of the complex number of the pixel
	double	pi; // imaginary part of the complex number of the pixel

	// Loop over each line and column of the window
	// to check each pixels
	y = -1;
	while (++y < HEIGHT) // line loop
	{
		x = -1;
		while (++x < WIDTH) // column loop
		{
			// Find pixel[x, y]'s corresponding complex number
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			// Evaluate it and set this pixel's color
			mandelbrot(guide, x, y, pr, pi);
		}
	}
}