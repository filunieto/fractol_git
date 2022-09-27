/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:43:18 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 21:39:55 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

//cambiar el nombre a la funcion
void	my_mlx_pixel_put(t_mlxwin *guide, int x, int y, int color)
{
	char	*dst;

	dst = guide->addr + (y * guide->line_length + x * (guide->bits_per_pixel / 8));
	*(unsigned int*)dst	= color;
}

//esta funcion creo que es la responsable de que todo sea mas rapido
static void	ft_new_image(t_mlxwin *guide)
{	
	guide->img = mlx_new_image(guide->img, WIDTH, HEIGHT);
	if (guide->img == NULL)
	{
		mlx_destroy_image(guide->mlx, guide->img);
		return;
	}
	guide->addr = mlx_get_data_addr(guide->img, &guide->bits_per_pixel, &guide->line_length, &guide->endian); //verificar que hace esta funcion
}

//cambiar a al funciond e nombre y pasar lso parametros de juli.
void	print_fractal1(t_mlxwin *guide) //funcion draw de Francesco
{
	// t_point point;
	int	x; // column
	int	y; // line
	t_fractol *f;
	int iteration;
	
	ft_new_image(guide);
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
			iteration = fractal_function(guide, x, y);
			if(iteration < MAX_ITERATIONS)
				my_mlx_pixel_put(guide, x, y, color(iteration)); //cambiar my_mlx_pixel_put(guide, x, y, color(iteration));
			if(iteration == MAX_ITERATIONS)
				my_mlx_pixel_put(guide, x, y, 000127255212);
			// c.real = f->view.min.x + (double)x * (f->view.max.x - f->view.min.x) / WIDTH;
			// c.imm = f->view.min.y + (double)y * (f->view.max.y - f->view.min.y) / HEIGHT;
			//print_fractal2(guide, x, y, c); //esta no hara falta, sea la equivalente a fractal function
		}
	}
	mlx_put_image_to_window(guide->mlx, guide->win, guide->img, 0, 0);
}

int	fractal_function(t_mlxwin *guide, int x, int y)
{
	int	iteration_value;

	iteration_value = 0;
	if (guide->f->fract_id == 1)
		iteration_value = mandelbrot(guide, x, y);
	else if (guide->f->fract_id == 2)
		iteration_value = julia(guide, x, y);
	else
		error_exit(NULL, guide, 1);
	return (iteration_value);
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