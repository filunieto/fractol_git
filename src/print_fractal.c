/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:43:18 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 17:08:07 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


//cambiar a al funciond e nombre y pasar lso parametros de juli
void	print_fractal1(t_mlxwin *guide)
{
	// t_point point;
	int	x; // column
	int	y; // line
	t_fractol *f;
	
	f = guide->f;
	t_complex c;
	// double	pr; // real part of the complex number of the pixel >>>c
	// double	pi; // imaginary part of the complex number of the pixel
	// Loop over each line and column of the window
	// to check each pixels
	y = -1;
	while (++y < HEIGHT) // line loop
	{
		x = -1;
		while (++x < WIDTH) // column loop
		{
			// Find pixel[x, y]'s corresponding complex number
			c.real = f->view.min.x + (double)x * (f->view.max.x - f->view.min.x) / WIDTH;
			c.imm = f->view.min.y + (double)y * (f->view.max.y - f->view.min.y) / HEIGHT;
			print_fractal2(guide, x, y, c);
		}
	}
}

void	print_fractal2(t_mlxwin *guide, int x, int y, t_complex c)
{
	if (guide->f->fract_id == 1)
		mandelbrot(guide, x, y, c);
	else if (guide->f->fract_id == 2)
		julia(guide, x, y, c);
	else
		error_exit(NULL, guide, 1);
}


void start_printing(t_mlxwin  *guide)
{
	// t_fractol *f;
	
	// f = guide->f;
	fractol_inicialize(guide);
	print_fractal1(guide);
	
	// mlx_hook(guide->win, EVENT_CLOSE_BTN, 0, check_keys, guide);
	// mlx_key_hook(guide->win, check_keys, guide);
	// mlx_mouse_hook(guide->win, check_mouse_hooks, guide);
	// mlx_loop(guide->mlx);

}