/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:43:18 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/11 00:08:27 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


//cambiar a al funciond e nombre y pasar lso parametros de juli
void	print_fractal1(t_mlxwin *guide)
{
	int	x; // column
	int	y; // line
	t_fractol *f;
	
	f = guide->f;
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
			print_fractal2(guide, x, y, pr, pi);
		}
	}
}

void	print_fractal2(t_mlxwin *guide, int x, int y, double pr, double pi)
{
	if (guide->f->fract_id == 1)
		mandelbrot(guide, x, y, pr, pi);
	else if (guide->f->fract_id == 2)
		julia(guide, x, y, pr, pi);
	else
		error_exit(NULL, guide, 1);
}


void start_printing(t_mlxwin  *guide)
{
	t_fractol *f;
	
	f = guide->f;
	fractol_inicialize(guide);
	print_fractal1(guide);
	
	// mlx_hook(guide->win, EVENT_CLOSE_BTN, 0, check_keys, guide);
	// mlx_key_hook(guide->win, check_keys, guide);
	// mlx_mouse_hook(guide->win, check_mouse_hooks, guide);
	// mlx_loop(guide->mlx);

}