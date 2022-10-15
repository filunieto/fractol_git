/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:43:18 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 13:17:21 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*
	This function makes everything faster
	https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/
void	my_mlx_pixel_put(t_mlxwin *guide, int x, int y, int color)
{
	char	*dst;

	dst = guide->addr + (y * guide->line_length + x * (guide->bits_per_pixel / 8));
	*(unsigned int*)dst	= color;
}

static void	ft_new_image(t_mlxwin *guide)
{	
	guide->img = mlx_new_image(guide->img, WIDTH, HEIGHT);
	if (guide->img == NULL)
	{
		mlx_destroy_image(guide->mlx, guide->img);
		return;
	}
	guide->addr = mlx_get_data_addr(guide->img, &guide->bits_per_pixel, &guide->line_length, &guide->endian);
}

/*
	Function that goes through each pixel 
	and transforms it into a complex number
	to check if it is stable or not and belongs 
	to the mandelbrot set.
	If it does not fit the formula we know it is unstable.
	We give a maximum number of iterations.
	For unstable numbers the value of iteration
	will give us the grade of instability and the colour.
*/
void	print_fractal(t_mlxwin *guide)
{
	int	x;
	int	y;
	t_fractol *f;
	int iteration;

	ft_new_image(guide);
	f = guide->f;
	t_complex c;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			iteration = fractal_function(guide, x, y);
			if(iteration < MAX_ITERATIONS)
				my_mlx_pixel_put(guide, x, y, color(iteration));
			if(iteration == MAX_ITERATIONS)
				my_mlx_pixel_put(guide, x, y,  get_argb(0, 148, 180, 159));
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
	else if (guide->f->fract_id == 3)
		iteration_value = burning_ship(guide, x, y);
	else if (guide->f->fract_id == 4)
		iteration_value = colibri(guide, x, y);
	else
		error_exit(NULL, guide, 1);
	return (iteration_value);
}
