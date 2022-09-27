/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:36 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:01 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	mandelbrot(t_mlxwin *guide, int x, int y, t_complex c)
{
	int	n = -1;	// Number of iterations 
	// double	z.real;	// Real part of Z
	// double	zi;	// Imaginary part of Z
	t_complex z;
	double	tmp;	// Temporary variable
	// Variable to determine if a number is in the set or not:
	int	is_in_set; 

	z.real = 0;
	z.imm = 0;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		// As long as we're not at the maximum number of iterations,
		// we iterate
		//recuerda que el modulo del vector del numero inmaginario tiene que ser menor que 2 >>> sqrt(z.real * z.real + z.imm * z.imm) > 2
		if ((z.real * z.real + z.imm * z.imm) > 4.0)
		{
			// If the absolute value of Z exceeds 2
			// (z.real * z.real + z.imm * z.imm) > 4.0 == sqrt(z.real * z.real + z.imm * z.imm) > 2
			is_in_set = 0;
			// We flag that this number tends toward infinity, 
			// and is therefore not part of the set
			// and we stop iterating
			break ;
		}
		// Calculate the Mandelbrot formula for the next iteration.Revisrra esto en lateoria
		//Usa usa la variable tmp: para no perder el valor de la parte imaginaria 
		//Z = (z.real^2 - z.imm^2 + Cr) || (2* z.real* z.imm + C)i >>> de la formul Z = Z * Z + C
		tmp = 2 * z.real * z.imm + c.imm; //(2* z.real* z.imm + C)i
		z.real = z.real * z.real - z.imm * z.imm + c.real; //(z.real^2 - z.imm^2 + Cr)
		z.imm = tmp;
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
