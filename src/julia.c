/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:40 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 16:57:08 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	julia(t_mlxwin *guide, int x, int y, t_complex z)
{
	// Here, z.real and z.imm are the values of the real and imaginary
	// parts of our pixel's complex number, unlike the
	// Mandelbrot formula that uses z.real = 0 and z.imm = 0
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((z.real * z.real + z.imm * z.imm) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		// ki and kr are predefined in the structure, but apart from
		// that, the formula is exactly the same as Mandelbrot
		tmp = 2 * z.real * z.imm + guide->f->k.imm;
		z.real = z.real * z.real - z.imm * z.imm +  guide->f->k.real;
		z.imm = tmp;
	}
	if (is_in_set == 1)
		mlx_pixel_put(guide->mlx, guide->win, x, y, 0x000000);
	else
		mlx_pixel_put(guide->mlx, guide->win, x, y, 0xFFFFFF);
}

