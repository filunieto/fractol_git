/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:40 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/14 21:52:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	check_julia_values(t_mlxwin *guide, int argc, char **argv)
{
	if (argc == 2)
	{
		guide->f->val_x = ft_atof("-0.805");
		guide->f->val_y = ft_atof("-0.2021");
	}
	else if (argc == 4)
	{
		//aqui hay que poner la condicion de chequear el numero, porque he puesto el valor 1.a 1.5 y ha hecho  un fractal
		guide->f->val_x = ft_atof(argv[2]);
		guide->f->val_y = ft_atof(argv[3]);
		if (guide->f->val_x > 2 || guide->f->val_x < -2
			|| guide->f->val_y > 2 || guide->f->val_y < -2)
			return(0);
	}
	else
		return (0);
	return(1);
}

int		 julia(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z = scaling_value(x, y,&(guide->f->view));
	c.real = (guide->f)->val_x;
	c.imm = (guide->f)->val_y;
	iteration = 0;
	while(((z.real * z.real) + (z.imm * z.imm)) < 4 && iteration < MAX_ITERATIONS)
	{
		sum.real = (z.real * z.real) - (z.imm * z.imm) + c.real;
		sum.imm = 2 * (z.real * z.imm) + c.imm;
		z.real = sum.real;
		z.imm = sum.imm;
		iteration++;
	}
	return(iteration);
}



// void	julia(t_mlxwin *guide, int x, int y, t_complex z)
// {
// 	// Here, z.real and z.imm are the values of the real and imaginary
// 	// parts of our pixel's complex number, unlike the
// 	// Mandelbrot formula that uses z.real = 0 and z.imm = 0
// 	int		n;
// 	double	tmp;
// 	int		is_in_set;

// 	n = -1;
// 	is_in_set = 1;
// 	while (++n < MAX_ITERATIONS)
// 	{
// 		if ((z.real * z.real + z.imm * z.imm) > 4.0)
// 		{
// 			is_in_set = 0;
// 			break ;
// 		}
// 		// ki and kr are predefined in the structure, but apart from
// 		// that, the formula is exactly the same as Mandelbrot
// 		tmp = 2 * z.real * z.imm + guide->f->k.imm;
// 		z.real = z.real * z.real - z.imm * z.imm +  guide->f->k.real;
// 		z.imm = tmp;
// 	}
// 	if (is_in_set == 1)
// 		mlx_pixel_put(guide->mlx, guide->win, x, y, 0x000000);
// 	else
// 		mlx_pixel_put(guide->mlx, guide->win, x, y, 0xFFFFFF);
// }